#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double discriminent(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double resolution(double a, double b, double c, double epsilon)
{
    if (abs(a) < epsilon)
    {
        printf("Ce n'est pas un polynôme du second degree\n");
        printf("La racine de %lf x + %lf = 0 est %lf\n", b, c, -c / b);
        return 0;
    }
    else
    {
        double delta = 0.0;
        delta = discriminent(a, b, c);
        printf("Le discriminent delta vaut : %lf\n", delta);
        if (delta < 0)
        {
            printf("Delta = %lf => %lf i^2\n", delta, delta);
            printf("Deux solutions : %lf + %lf i et %lf + %lf i\n", -b / (2 * a), (-sqrt(-delta)) / (2 * a), -b / (2 * a), (sqrt(-delta)) / (2 * a));
            return 0;
        }
        else if (abs(delta) < epsilon)
        {
            printf("Une solution double : %lf\n", -b / (2 * a));
            return 0;
        }
        else
        {
            printf("Deux solutions : %lf et %lf\n", (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
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
    polynome(&a, &b, &c);
    resolution(a, b, c, epsilon);
    return 0;
}