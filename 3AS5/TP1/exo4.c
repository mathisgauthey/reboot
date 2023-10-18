#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    printf("Enter a :\n");
    scanf("%d", &a);
    printf("Enter b :\n");
    scanf("%d", &b);
    c = a;
    a = b;
    b = c;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}