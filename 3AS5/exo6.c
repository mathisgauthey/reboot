#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N, compteur = 0;
    printf("Veuillez choisir un nombre N: \n");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        compteur += i;
    }
    printf("La somme des %d premiers entiers est %d.\n", N, compteur);
    return 0;
}