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

float polynome(float a,float b,float c,float *r1, float *r2)
{
	float delta=b*b-4*a*c;
    if(delta>0)
    {
        *r1=(-b-sqrt(delta))/(2*a);
        *r2=(-b+sqrt(delta))/(2*a);
    }
    else if(delta==0.0)
    {
        *r1=-b/(2*a);
        *r2=-b/(2*a);
    }
    else
    {
        *r1=-b/(2*a);
        *r2=sqrt(fabs(delta))/(2*a);
    }
    return delta;
}

int main (int argc, char*argv[])
{
    float a,b,c,r1,r2,delta;
    printf("Aujourd'hui on calcule les discriminants d'un polynome.\nDonne moi dans l'ordre les coeffs a,b et c du polynome ax^2+bx+c \n");
    scanf("%f""%f""%f",&a,&b,&c);
    printf("Ton polynome est %fx^2+%fx+%f \n",a,b,c);
    delta=polynome(a,b,c,&r1,&r2);
    if(a==0)
    {
        printf("C'est un pol de deg 1 et sa racine vaut %f \n",equationez(b,c));
    }
    if(delta>0)
    {
    	printf("Les 2 racines sont %f et %f",r1,r2);
    }
    else if(delta==0)
    {
    	printf("La racine double est %f",r1);
    }
    else
    {
    	printf("Les 2 racines sont %f+i%f et %f-i%f",r1,r2,r1,r2);
    }
    return 0;
}
