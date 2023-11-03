#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void choix_donnees(double *y_plage, double *y_eau, double *x_tot)
{
    printf("Veuillez choisir la distance dans le sable entre le sauveteur et l'eau (en m) : \n");
    scanf("%lf", y_plage);
    printf("Le sauveteur se trouve à une distance de %.2lf m de l'eau.\n", *y_plage);
    printf("Veuillez choisir la distance dans l'eau entre le touriste et la plage (en m) : \n");
    scanf("%lf", y_eau);
    printf("Le touriste se trouve à une distance de %.2lf m de la plage.\n", *y_eau);
    printf("Veuillez choisir la distance latérale entre le sauveteur et le touriste (en m) : \n");
    scanf("%lf", x_tot);
    printf("La distance latérale entre le sauveteur et le touriste est de %.2lf m.\n", *x_tot);
}

double function(double y_plage, double y_eau, double x_tot, double v_plage, double v_eau, double x)
{
    return 1 / (v_plage * sqrt(1 + (y_plage * y_plage) / (x * x))) + (x - x_tot) / (v_eau * sqrt((x_tot - x) * (x_tot - x) + y_eau * y_eau));
}

void resolution(double y_plage, double y_eau, double x_tot, double v_plage, double v_eau, double error_max, double *residu, int *iteration, double *x_opti)
{
    double xg = 0.0, xd = x_tot;
    do
    {
        *x_opti = xd - function(y_plage, y_eau, x_tot, v_plage, v_eau, xd) * ((xd - xg) / (function(y_plage, y_eau, x_tot, v_plage, v_eau, xd) - function(y_plage, y_eau, x_tot, v_plage, v_eau, xg)));
        *residu = fabs(function(y_plage, y_eau, x_tot, v_plage, v_eau, *x_opti));
        if (function(y_plage, y_eau, x_tot, v_plage, v_eau, *x_opti) * function(y_plage, y_eau, x_tot, v_plage, v_eau, xd) < 0.0)
            xg = *x_opti;
        if (function(y_plage, y_eau, x_tot, v_plage, v_eau, *x_opti) * function(y_plage, y_eau, x_tot, v_plage, v_eau, xg) < 0.0)
            xd = *x_opti;
        *iteration += 1;
    } while (*residu > error_max);
}

affiche_res(double x_opti, int iteration, double affiche_res)
{
    printf("La solution optimale est de plonger dans l'eau à x_opti=%lf\nLe calcul a prit %d itérations et l'erreur finale est de %.16lf\n", x_opti, iteration, affiche_res);
}

int main(int argc, char *argv[])
{
    double y_plage, y_eau, x_tot, x_opti;
    double v_plage = 5.0, v_eau = 2.0;
    double error_max = 1e-12, residu;
    int iteration = 0;
    choix_donnees(&y_plage, &y_eau, &x_tot);
    resolution(y_plage, y_eau, x_tot, v_plage, v_eau, error_max, &residu, &iteration, &x_opti);
    affiche_res(x_opti, iteration, residu);
    return 0;
}