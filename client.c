//
// Created by Cavide Balki Gemirter on 19.10.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#include <regex.h>
#include "common.h"
#include "util.c"

char* initialCommand;

Command getCommand(regex_t regex, char *input) {
    int res;
    regmatch_t pmatch[4];

    res = regexec(&regex, input, 4, pmatch, REG_NOTBOL);

    Command cmd;

    if (res == 0) {
        printf("Match Found for %s\n", input);

        cmd.operand1 = substr(input, pmatch[1].rm_so, pmatch[1].rm_eo);
        cmd.operator = substr(input, pmatch[2].rm_so, pmatch[2].rm_eo);
        cmd.operand2 = substr(input, pmatch[3].rm_so, pmatch[3].rm_eo);

    } else if (res == REG_NOMATCH) {
        printf("NO match for %s\n", input);
        cmd.operator = NULL;
    }

    return cmd;
}

char* executeCommand(CLIENT *cl, char hostname[256], char *input) {
    regex_t regex = loadRegex("([0-9.]+|inf)[ ]*([+*\\/-])[ ]*([0-9.]+|inf)");
    printf("Input\t\t: %s\n", input);

    Command command = getCommand(regex, input);
    printf("Operand 1\t\t: %s\n", command.operand1);
    printf("Operator\t\t: %s\n", command.operator);
    printf("Operand 2\t\t: %s\n", command.operand2);

    char *data = (char *) malloc(1 + strlen(command.operand1) + strlen(DELIMINATOR) + strlen(command.operand2));
    strcpy(data, command.operand1);
    strcat(data, DELIMINATOR);
    strcat(data, command.operand2);

    printf("Getting ready to call %s\n", data);

    double *opResult;

    switch (command.operator[0]) {
        case '+': {
            opResult = add_1(&data, cl);
            break;
        }
        case '-': {
            opResult = subtract_1(&data, cl);
            break;
        }
        case '*': {
            opResult = multiply_1(&data, cl);
            break;
        }
        case '/': {
            opResult = divide_1(&data, cl);
            break;
        }
    }

    printf("Back from remote call %f\n", *opResult);

    char full[1024];
    strcpy(full, "(");
    strcat(full, command.operand1);
    strcat(full, command.operator);
    strcat(full, command.operand2);
    strcat(full, ")");

    char* input2 = replace(input, full, toString(*opResult));

    strcpy(full, command.operand1);
    strcat(full, command.operator);
    strcat(full, command.operand2);

    input2 = replace(input2, full, toString(*opResult));

    if(strchr(input2, '+') == NULL && strchr(input2, '-') == NULL && strchr(input2, '*') == NULL && strchr(input2, '/') == NULL){
        printf("\nFinal result %s = %f\n", initialCommand, *opResult);
        exit(EXIT_SUCCESS);
    }

    return input2;
}

main(int argc, char *argv[]) {
    char hostname[256];

    if (argc != 3) {
        printf("Usage: client hostname command\n");
        exit(EXIT_FAILURE);
    }

    strcpy(hostname, argv[1]);
    printf("Hostname\t: %s\n", hostname);

    CLIENT *cl;
    cl = clnt_create(hostname, RPC_CALCULATOR_PROG, RPC_CALCULATOR_VERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror(hostname);
        exit(EXIT_FAILURE);
    }

    printf("Ready\n");

    char *input = argv[2];

    initialCommand = input;

    while(TRUE){
        input = executeCommand(cl, hostname, input);
    }
}



