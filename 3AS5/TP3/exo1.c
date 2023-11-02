#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double discriminent(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double resolution(double a, double b, double c, double epsilon, double *r1, double *r2)
{
    if (abs(a) < epsilon)
    {
        printf("Ce n'est pas un polynôme du second degree\n");
        *r1 = -c / b;
        *r2 = *r1;
        printf("La racine de %lf x + %lf = 0 est %lf\n", b, c, *r1);
        return 0;
    }
    else
    {
        double delta = 0.0;
        delta = discriminent(a, b, c);
        printf("Le discriminent delta vaut : %lf\n", delta);
        if (delta < 0)
        {
            *r1 = -b / (2 * a);
            *r2 = sqrt(fabs(delta)) / (2 * a);
            printf("Delta = %lf => %lf i^2\n", delta, delta);
            printf("Deux solutions : %lf + i %lf et %lf - i %lf\n", *r1, *r2, *r1, *r2);
            return 0;
        }
        else if (abs(delta) < epsilon)
        {
            *r1 = -b / (2 * a);
            *r2 = *r1;
            printf("Une solution double : %lf\n", *r1);
            return 0;
        }
        else
        {
            *r1 = (-b - sqrt(delta)) / (2 * a);
            *r2 = (-b + sqrt(delta)) / (2 * a);
            printf("Deux solutions : %lf et %lf\n", *r1, *r2);
            return 0;
        }
    }
}

void polynome(double *a, double *b, double *c)
{
    printf("Entrez les coefficients a, b et c du polynome a x^2 + b x + c = 0\n");
    scanf("%lf", a);
    printf("%lf x^2 + b x + c\n", *a);
    scanf("%lf", b);
    printf("%lf x^2 + %lf x + c\n", *a, *b);
    scanf("%lf", c);
    printf("%lf x^2 + %lf x + %lf\n", *a, *b, *c);
}

int main(int argc, char *argv[])
{
    double a = 0.0, b = 0.0, c = 0.0;
    double epsilon = 1e-3;
    double r1 = 0.0, r2 = 0.0;
    polynome(&a, &b, &c);
    resolution(a, b, c, epsilon, &r1, &r2);
    printf("Les solutions sont %lf et %lf\n", r1, r2);
    return 0;
}