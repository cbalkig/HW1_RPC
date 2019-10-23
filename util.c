//
// Created by Cavide Balki Gemirter on 21.10.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

static char* DELIMINATOR = "|";

typedef struct {
    char* operand1;
    char* operand2;
    char* operator;
} Command;

typedef struct{
    int operand1;
    int operand2;
} Operands;

static regex_t loadRegex(char* REGEX) {
    regex_t regex;

    int res;
    char err_buf[BUFSIZ];

    if((res = regcomp(&regex, REGEX, REG_EXTENDED)) != 0)
    {
        regerror(res, &regex, err_buf, BUFSIZ);
        printf("regcomp: %s\n", err_buf);
        exit(res);
    }

    return regex;
}

static Operands split(char* input) {
    Operands operands;

    char data[strlen(input)];
    strcpy(data, input);

    char *token = strtok (data, DELIMINATOR);
    operands.operand1 = atof(token);

    token = strtok (NULL, DELIMINATOR);
    operands.operand2 = atof(token);

    return operands;
}

static char* substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char*) malloc(sizeof(char) * (len + 1));
    int i;
    for (i = m; i < n && (*src != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';

    return dest - len;
};

static char* toString(float d){
    char buf[100];
    gcvt(d, 6, buf);
    return buf;
};

static char* replace(char *str, char *orig, char *rep)
{
    static char buffer[4096];
    char *p;

    if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
        return str;

    strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
    buffer[p-str] = '\0';

    sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

    return buffer;
};
