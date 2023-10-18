#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int age;
    float height;
    printf("Enter your age :\n");
    scanf("%d", &age);
    printf("Enter your height in m :\n");
    scanf("%f", &height);
    printf("You're %d years old and %f m tall. \n", age, height);
    return 0;
}