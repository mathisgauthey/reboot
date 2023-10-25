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

int fibonacci(int k, int P0, int P1)
{
    int pn = 0, pn_1 = P1, pn_2 = P0;
    printf("%d\n%d\n", pn_2, pn_1);
    for (int i = 2; i <= k; i++)
    {
        pn = pn_1 + pn_2;
        printf("%d\n", pn);
        pn_2 = pn_1;
        pn_1 = pn;
    }
}

void affiche_246()
{
    int i, j, k;
    for (int i = 2; i <= 6; i += 2)
    {
        for (int j = 2; j <= 6; j += 2)
        {
            for (int k = 2; k <= 6; k += 2)
            {
                printf("%d %d %d\n", i, j, k);
            }
        }
    }
}

void choix_val_inter(int a, int b)
{
    int choix;
    printf("Veuillez choisir une valeur entre %d et %d: \n", a, b);
    scanf("%d", &choix);
    while (choix < a || choix > b)
    {
        printf("Erreur, le nombre choisis n'est pas entre %d et %d.\n", a, b);
        printf("Veuillez choisir une valeur entre %d et %d: \n", a, b);
        scanf("%d", &choix);
    }
    printf("Vous avez choisi %d, bravo sombre idiot !\n", choix);
}

main(int argc, char *argv[])
{
    // int N, somme_entier = 0, somme_entier_pair = 0, somme_entier_impair = 0, compteur;
    // printf("Veuillez choisir un nombre N: \n");
    // scanf("%d", &N);
    // somme_entier = somme_entiers(N);
    // somme_entier_pair = somme_entiers_pair(N);
    // somme_entier_impair = somme_entiers_impair(N);
    // printf("La somme des %d premiers entiers est %d.\n", N, somme_entier);
    // printf("La somme des %d premiers entiers pairs est %d.\n", N, somme_entier_pair);
    // printf("La somme des %d premiers entiers impairs est %d.\n", N, somme_entier_impair);

    // int k = 0, fibo = 0, P0 = 0, P1 = 1;
    // printf("Veuillez choisir un nombre k: \n");
    // scanf("%d", &k);
    // printf("Les %d premiers termes de la suite de Fibonacci sont: \n", k);
    // fibonacci(k, P0, P1);

    // affiche_246();

    int a = -23, b = 7;

    choix_val_inter(a, b);

    return 0;
}