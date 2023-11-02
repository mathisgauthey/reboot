#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void avion(double rho, double V, double S, double T, double alpha, double *portance, double *Cl, double *trainee, double *Cd, double *finesse)
{
    double Tx, Ty;
    Tx = T * cos(alpha);
    Ty = T * sin(alpha);
    *Cl = Tx / (0.5 * rho * S * V * V);
    *Cd = Ty / (0.5 * rho * S * V * V);
    *portance = 0.5 * rho * *Cl * S * V * V;
    *trainee = 0.5 * rho * *Cd * S * V * V;
    *finesse = (*portance) / (*trainee);
}

void affiche_res(double rho, double V, double S, double T, double alpha, double portance, double Cl, double trainee, double Cd, double finesse)
{
    printf("rho = %lf\n", rho);
    printf("V = %lf\n", V);
    printf("S = %lf\n", S);
    printf("T = %lf\n", T);
    printf("alpha = %lf\n", alpha);
    printf("portance = %lf\n", portance);
    printf("Cl = %lf\n", Cl);
    printf("trainee = %lf\n", trainee);
    printf("Cd = %lf\n", Cd);
    printf("finesse = %lf\n", finesse);
}

void choix_donnees(double *rho, double *V, double *S, double *T, double *alpha)
{
    printf("rho = \n");
    scanf("%lf", rho);
    printf("rho = %lf\n", *rho);
    printf("V = \n");
    scanf("%lf", V);
    printf("V = %lf\n", *V);
    printf("S = \n");
    scanf("%lf", S);
    printf("S = %lf\n", *S);
    printf("T = \n");
    scanf("%lf", T);
    printf("T = %lf\n", *T);
    printf("alpha = \n");
    scanf("%lf", alpha);
    printf("alpha = %lf\n", *alpha);
}

int main(int argc, char *argv[])
{
    double rho, V, S, T, alpha;
    double portance, Cl, trainee, Cd, finesse;
    choix_donnees(&rho, &V, &S, &T, &alpha);
    avion(rho, V, S, T, alpha, &portance, &Cl, &trainee, &Cd, &finesse);
    affiche_res(rho, V, S, T, alpha, portance, Cl, trainee, Cd, finesse);
    return 0;
}