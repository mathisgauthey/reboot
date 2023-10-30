#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double calculSigma(double epsilon, double E)
{
    return epsilon * E;
}

double calculDeformation(double sigma, double E)
{
    return sigma / E;
}

double calculModuleYoung(double sigma, double epsilon)
{
    return sigma / epsilon;
}

double calculotron(int choix)
{
    double sigma = 0.0, epsilon = 0.0, E = 0.0;
    switch (choix)
    {
    case 1:
        printf("Entrez la déformation : ");
        scanf("%lf", &epsilon);
        printf("Entrez le module d'Young : ");
        scanf("%lf", &E);
        sigma = calculSigma(epsilon, E);
        printf("Le résultat du calcul de la contrainte est : %lf\n", sigma);
        break;
    case 2:
        printf("Entrez la contrainte : ");
        scanf("%lf", &sigma);
        printf("Entrez le module d'Young : ");
        scanf("%lf", &E);
        epsilon = calculDeformation(sigma, E);
        printf("Le résultat du calcul de la déformation est : %lf\n", epsilon);
        break;
    case 3:
        printf("Entrez la contrainte : ");
        scanf("%lf", &sigma);
        printf("Entrez la déformation : ");
        scanf("%lf", &epsilon);
        E = calculModuleYoung(sigma, epsilon);
        printf("Le résultat du calcul du module d'Young est : %lf\n", E);
        break;
    default:
        printf("Erreur dans le choix du calcul !\n");
        break;
    }
}

int choixCalcul()
{
    int choix;
    do
    {
        printf("Choisissez le calcul à effectuer :\n");
        printf("1. Calcul de la contrainte en connaissant la déformation et le module d'Young\n");
        printf("2. Calcul de la déformation en connaissant la contrainte et le module d'Young\n");
        printf("3. Calcul du module d'Young en connaissant la contrainte et la déformation\n");
        printf("4. Quitter\n");
        scanf("%d", &choix);
        if (choix < 1 || choix > 4)
        {
            printf("Choix invalide !\n");
        }
        else if (choix == 4)
        {
            printf("Au revoir !\n");
            break;
        }
    } while (choix < 1 || choix > 4);
    return choix;
}

int main(int argc, char *argv[])
{
    calculotron(choixCalcul());
    return 0;
}