#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
double const PESANTEUR = 9.81;
double const PI = 3.14159265359;

// Site pour vérifier les valeurs numériques : https://www.edu.gov.mb.ca/m12/frpub/ped/sn/phys/dmo_12/word/reg_1_ann_31.docx
// NB : Impossible de choisir un angle de 90° pour ce résultat, cas limite des formules utilisées.

void choix_donnees(double *h0, double *v0, double *alpha)
{
    printf("Veuillez entrer la hauteur initiale en mètres: \n");
    scanf("%lf", h0);
    printf("La hauteur initiale est de %lf m\n", *h0);
    printf("Veuillez entrer la vitesse initiale en mètres par seconde: \n");
    scanf("%lf", v0);
    printf("La vitesse initiale est de %lf m/s\n", *v0);
    printf("Veuillez entrer l'angle de tir en degrés: \n");
    scanf("%lf", alpha);
    printf("L'angle de tir est de %lf degrés\n", *alpha);
    printf("Le tir est réalisé à une hauteur h0 = %lf m, avec une vitesse initiale v0 = %lf m/s et un angle de tir alpha = %lf degrés\n", *h0, *v0, *alpha);
    *alpha = *alpha * PI / 180;
    printf("L'angle de tir est de %lf radians\n", *alpha);
}

double polynome(double a, double b, double c)
{
    double res, r1, r2, delta;
    delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        r1 = (-b - sqrt(delta)) / (2 * a);
        r2 = (-b + sqrt(delta)) / (2 * a);
        if (r1 > r2)
        {
            res = r1;
        }
        else
        {
            res = r2;
        }
    }
    else
    {
        printf("La trajectoire est anormale, erreur fatale \n");
    }
    return res;
}

void ballistique(double h0, double v0, double alpha, double *hmax, double *t_hmax, double *d_impact, double *t_impact, double *v_impact)
{
    double a, b, c;
    a = (-0.5 * PESANTEUR) / (v0 * v0 * cos(alpha) * cos(alpha));
    b = tan(alpha);
    c = h0;
    *d_impact = polynome(a, b, c);
    *t_impact = *d_impact / (v0 * cos(alpha));
    *hmax = v0 * v0 * sin(alpha) * sin(alpha) / (2 * PESANTEUR) + h0;
    *t_hmax = (v0 * sin(alpha)) / PESANTEUR;
    *v_impact = sqrt(v0 * v0 - v0 * v0 * sin(alpha) * sin(alpha));
}

void affiche_res(double hmax, double t_hmax, double d_impact, double t_impact, double v_impact)
{
    printf("Le tir atteint une hauteur maximale de %lf m à t = %lf s\n", hmax, t_hmax);
    printf("Le tir atteint une distance d'impact de %lf m à t = %lf s et avec une vitesse de %lf m/s\n", d_impact, t_impact, v_impact);
}

int main(int argc, char *argv[])
{
    double h0 = 0.0, v0 = 0.0, alpha = 0.0;
    double hmax = 0.0, t_hmax = 0.0, d_impact = 0.0, t_impact = 0.0, v_impact = 0.0;
    choix_donnees(&h0, &v0, &alpha);
    ballistique(h0, v0, alpha, &hmax, &t_hmax, &d_impact, &t_impact, &v_impact);
    affiche_res(hmax, t_hmax, d_impact, t_impact, v_impact);
    return 0;
}