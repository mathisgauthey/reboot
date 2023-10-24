#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // int choix, abs_value, choix_specifique;
    int a, b, c, d;

    // printf("Choisissez un nombre entier: \n");
    // scanf("%d", &choix);
    // printf("Vous avez choisi %d\n", choix);
    // if (choix < 0)
    // {
    //     printf("Le nombre est négatif\n");
    //     abs_value = -choix;
    // }
    // else if (choix > 0)
    // {
    //     printf("Le nombre est positif\n");
    //     abs_value = choix;
    // }
    // else if (choix == 0)
    // {
    //     printf("Le nombre est nul\n");
    //     abs_value = 0;
    // }

    // printf("La valeur absolue de ce nombre est %d\n", abs_value);

    // do
    // {
    //     printf("Choisissez un nombre entier entre 17 et 42: \n");
    //     scanf("%d", &choix_specifique);
    //     if (choix_specifique < 17 || choix_specifique > 42)
    //     {
    //         printf("Le nombre n'est pas compris entre 17 et 42\n");
    //     }
    //     else
    //     {
    //         printf("Vous avez choisi %d, bravo ! \n", choix_specifique);
    //     }

    // } while (choix_specifique < 17 || choix_specifique > 42);

    printf("Choisissez trois nombres entiers: \n");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
    {
        d = a;
        a = b;
        b = d;
    }
    if (b > c)
    {
        d = b;
        b = c;
        c = d;
    }
    if (a > b)
    {
        d = a;
        a = b;
        b = d;
    }

    printf("Je vous ai rangé ça par ordre croissant: %d %d %d\n", a, b, c);

    return 0;
}