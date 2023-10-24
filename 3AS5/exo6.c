#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int somme_entiers(int N)
{
    int compteur = 0;
    for (int i = 1; i <= N; i++)
    {
        compteur += i;
    }
    return compteur;
}

int somme_entiers_pair(int N)
{
    int compteur = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            compteur += i;
        }
    }
    return compteur;
}

int somme_entiers_impair(int N)
{
    int compteur = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 != 0)
        {
            compteur += i;
        }
    }
    return compteur;
}

int main(int argc, char *argv[])
{
    int N, somme_entier = 0, somme_entier_pair = 0, somme_entier_impair = 0, compteur;
    printf("Veuillez choisir un nombre N: \n");
    scanf("%d", &N);
    somme_entier = somme_entiers(N);
    somme_entier_pair = somme_entiers_pair(N);
    somme_entier_impair = somme_entiers_impair(N);
    printf("La somme des %d premiers entiers est %d.\n", N, somme_entier);
    printf("La somme des %d premiers entiers pairs est %d.\n", N, somme_entier_pair);
    printf("La somme des %d premiers entiers impairs est %d.\n", N, somme_entier_impair);
    return 0;
}