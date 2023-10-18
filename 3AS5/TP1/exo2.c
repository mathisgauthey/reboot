#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a = 2, b = 3, div_int;
    float c = 2.0, d = 3.0, div_float;
    double e = 2.0, f = 3.0, div_double;
    div_int = a / b;
    div_float = c / d;
    div_double = e / f;
    printf("Results from int division is %d \n", div_int);
    printf("Results from float division is %f \n", div_float);
    printf("Results from double division is %lf \n", div_double);
    return 0;
}