#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float equationez(float b,float c) //Calcule la racine d'un pol de deg 1
{
    float res;
    res=-c/b;
    return res;
}

float discriminent(float a, float b, float c) //Calcule le det d'un pol de deg 2
{
    float delta=b*b-4*a*c;
    return delta;
}

void affichage(float a,float b,float c,float delta)
{
    float x1,x2;
    if(delta>0)
    {
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        printf("Les 2 racines sont %f et %f \n",x1,x2);
    }
    else if(delta==0.0)
    {
        x1=-b/(2*a);
        printf("La racine double vaut %f \n",x1);
    }
    else
    {
        printf("Oulaaaa mon pote, t'as crus qu'on avait la motiv de programmer les parties reelles et tout l'bordel ? Nope *run away* \n");
    }
}

int main (int argc, char*argv[])
{
    float a,b,c;
    printf("Aujourd'hui on calcule les discriminants d'un polynome.\nDonne moi dans l'ordre les coeffs a,b et c du polynome ax^2+bx+c \n");
    scanf("%f""%f""%f",&a,&b,&c);
    printf("Ton polynome est %fx^2+%fx+%f \n",a,b,c);
    if(a==0)
    {
        printf("C'est un pol de deg 1 et sa racine vaut %f \n",equationez(b,c));
    }
    else
    {
        affichage(a,b,c,discriminent(a,b,c));
    }
    return 0;
}
