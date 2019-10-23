//
// Created by Cavide Balki Gemirter on 19.10.2019.
//
#include "util.c"

double *add_1_svc(char** msg){
    static double result;
    printf("Remote ADD call : %s\n", *msg);
    Operands data = split(*msg);
    result = data.operand1 + data.operand2;
    printf("Remote call result : %f\n", result);
    return(&result);
}

double **subtract_1_svc(char** msg) {
    static double result;
    printf("Remote SUBSTRACT call : %s\n", *msg);
    Operands data = split(*msg);
    result = data.operand1 - data.operand2;
    printf("Remote call result : %f\n", result);
    return(&result);
}

double **multiply_1_svc(char** msg) {
    static double result;
    printf("Remote MULTIPLY call : %s\n", *msg);
    Operands data = split(*msg);
    result = data.operand1 * data.operand2;
    printf("Remote call result : %f\n", result);
    return(&result);
}

double **divide_1_svc(char** msg) {
    static double result;
    printf("Remote DIVIDE call : %s\n", *msg);
    Operands data = split(*msg);
    result = (double) data.operand1 / data.operand2;
    printf("Remote call result : %f\n", result);
    return(&result);
}
