//
// Created by Cavide Balki Gemirter on 20.10.2019.2
//
#include <stdio.h>

int main(){
    double x;
    x = 3 + 4;
    printf("x = %f\n", x);
    printf("&x = %f\n", &x);

    double *y;
    *y = x;
    printf("y = %f\n", y);
    printf("&y = %f\n", &y);
    printf("*y = %i\n", *y);

    double **z;
    *z = y;
    printf("z = %f\n", z);
    printf("&z = %f\n", &z);
    printf("*z = %i\n", *z);
}
