//
// Created by Cavide Balki Gemirter on 19.10.2019.
//
#include "util.c"

double *add_1_svc(char** msg){
    static double result;
    Operands data = split(*msg);
    result = data.operand1 + data.operand2;
    return(&result);
}

double **subtract_1_svc(char** msg) {
    static double result;
    Operands data = split(*msg);
    result = data.operand1 - data.operand2;
    return(&result);
}

double **multiply_1_svc(char** msg) {
    static double result;
    Operands data = split(*msg);
    result = data.operand1 * data.operand2;
    return(&result);
}

double **divide_1_svc(char** msg) {
    static double result;
    Operands data = split(*msg);
    result = (double) data.operand1 / data.operand2;
    return(&result);
}