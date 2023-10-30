#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double f(double x)
{
    return (x - cos(x));
}

double fprime(double x)
{
    return (1 + sin(x));
}

void pointfixe(double x0, double epsilon)
{
    double xn1 = 0.0, xn = x0;
    double erreur;
    int compteur = 0;
    do
    {
        xn1 = cos(xn);
        erreur = fabs(xn1 - xn);
        xn = xn1;
        compteur += 1;
    } while (erreur > epsilon);
    printf("La solution par la méthode du point fixe est %lf et à été trouvée en %d itérations.\n", xn1, compteur);
}

void newton(double x0, double epsilon)
{
    double xn1 = 0.0, xn = x0;
    double erreur;
    int compteur = 0;
    do
    {
        xn1 = xn - f(xn) / fprime(xn);
        erreur = fabs(xn1 - xn);
        xn = xn1;
        compteur += 1;
    } while (erreur > epsilon);
    printf("La solution par la méthode de Newton est %lf et à été trouvée en %d itérations.\n", xn1, compteur);
}

void dichotomie(double a, double b, double epsilon)
{
    double c, erreur;
    int compteur = 0;
    do
    {
        c = (a + b) / 2;
        erreur = fabs(b - a);
        if (f(a) * f(c) > 0.0)
        {
            a = c;
        }
        else if (f(a) * f(c) < 0.0)
        {
            b = c;
        }
        else
        {
            printf("C'est la merde\n");
        }
        compteur += 1;
    } while (erreur > epsilon);
    printf("La solution par la méthode de Newton est %lf et à été trouvée en %d itérations.\n", c, compteur);
}

int main(int argc, char *argv[])
{
    double x0 = 0.5;
    double a = 0.0, b = 1.0;
    double epsilon = 1e-12;
    double correction = 0.739085;
    printf("La solution exacte est %lf.\n", correction);
    pointfixe(x0, epsilon);
    newton(x0, epsilon);
    dichotomie(a, b, epsilon);
    return 0;
}