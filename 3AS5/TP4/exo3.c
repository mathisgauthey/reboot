#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MASSE 0.1
#define BETA 0.5
#define GRAVITE 9.806

void data_choice(int *tailleTab, double *tempsMax, double *deltaT)
{
    printf("Enter the size of the array : ");
    scanf("%d", tailleTab);
    printf("Enter the maximum time of integration : ");
    scanf("%lf", tempsMax);
    *deltaT = *tempsMax / *tailleTab;
    printf("===== Data Inputed =====\n");
    printf("Size of the array : %d\n", *tailleTab);
    printf("Maximum time of integration : %lf\n", *tempsMax);
    printf("Increment of time : %lf\n", *deltaT);
}

double dvdt(double v)
{
    return ((MASSE * GRAVITE) - (BETA * v * v)) / MASSE;
}

void timeTable(double *temps, int tailleTab, double deltaT)
{
    for (int i = 0; i < tailleTab; i++)
    {
        temps[i] = i * deltaT;
    }
}

void speedTable(double *vitesse, int tailleTab, double deltaT)
{
    vitesse[0] = 0.0;
    for (int i = 0; i < tailleTab; i++)
    {
        vitesse[i + 1] = vitesse[i] + deltaT * dvdt(vitesse[i]);
    }
}

void results(double *temps, double *vitesse, double tailleTab)
{
    FILE *res;
    res = fopen("res.csv", "w+");
    if (res != NULL)
    {
        for (int i = 0; i < tailleTab; i++)
        {
            fprintf(res, "%f;%f\n", temps[i], vitesse[i]);
        }
    }
    else
    {
        printf("Erreur");
    }
    fclose(res);
}

int main(int argc, char *argv[])
{
    int tailleTab;
    double tempsMax, deltaT;
    data_choice(&tailleTab, &tempsMax, &deltaT);
    double *temps = malloc(tailleTab * sizeof(double));
    double *vitesse = malloc(tailleTab * sizeof(double));
    timeTable(temps, tailleTab, deltaT);
    speedTable(vitesse, tailleTab, deltaT);
    results(temps, vitesse, tailleTab);
    return 0;
}