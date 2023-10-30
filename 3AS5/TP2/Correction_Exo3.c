#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fct(double x)
{
    double res;
    res=x-cos(x);
    return res;
}

void pointfixe(double x0,double eps)
{
    double xn_1,xn=x0,erreur;
    int compteur=0;
    do
    {
        xn_1=cos(xn);
        erreur=fabs(xn_1-xn);
        xn=xn_1;
        compteur+=1;
    }while(erreur>eps);
    printf("La racine de f par la methode des points fixes est %.20lf \nLa methode a necessité %d\n",xn_1,compteur);
}

void newton(double x0,double eps)
{
    double xn_1,xn=x0,erreur;
    int compteur=0;
    do
    {
        xn_1=xn - ( (xn-cos(xn)) / (1+sin(xn)) );
        erreur=fabs((xn_1-xn)/xn_1);
        xn=xn_1;
        compteur+=1;
    }while(erreur>eps);
    printf("La racine de f par la methode de newton est %.20lf \nLa methode a necessité %d\n",xn_1,compteur);
}

void dichotomie(double eps,double a,double b)
{
    double c, erreur;
    int compteur=0;
    do
    {
        c=(a+b)/2;
        erreur=fabs(b-a);
        if(fct(a)*fct(c)>0.0)
        {
            a=c;
        }
        else if(fct(a)*fct(c)<0.0)
        {
            b=c;
        }
        else
        {
            printf("C'est la merde\n");
        }
        compteur+=1;
    }while(erreur>eps);
    printf("La racine de f par la methode de newton est %.20lf \nLa methode a necessité %d\n",c,compteur);
}


int main (int argc, char*argv[])
{
    double x0=0.5,eps=pow(10,-12),a=0,b=1;  //ATTENTION x0 doit appartenir a [0,1]
   // printf("Veuillez choisir l'erreur attendue\n");
   // scanf("%f",eps);
    pointfixe(x0,eps);
    newton(x0,eps);
    dichotomie(eps,a,b);
    return 0;
}
