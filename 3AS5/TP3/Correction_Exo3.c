#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double const PESANTEUR=9.81;
double const PI=3.14159265359;

double polynome(double a,double b,double c) //On veux juste l'impact a droite
{
    double res, r1, r2, delta;
    delta=b*b-4*a*c;
    if(delta>0)
    {
        r1=(-b-sqrt(delta))/(2*a);
        r2=(-b+sqrt(delta))/(2*a);
        if(r1>r2)
        {
            res=r1;
        }
        else
        {
            res=r2;
        }
    }
    else
    {
        printf("La trajectoire est anormale, erreur fatale \n");
    }
    return res;
}

void balistique(double V0, double alpha, double h0, double *tmax,double *ymax, double *timpact, double *d, double *Vimpact)
{
	double a,b,c;
	/* 
    Vx=V0*cos(alpha);
	Vy=V0*sin(alpha)-PESANTEUR*t;
	X=V0*cos(alpha)*t;
	Y=-0.5*PESANTEUR*t*t + V0*sin(alpha)*t + h0; 
    */

	*tmax=(V0*sin(alpha))/PESANTEUR;
	*ymax = -0.5 * PESANTEUR * *tmax * *tmax + V0 * sin(alpha) * *tmax + h0;

    a=-0.5*PESANTEUR;
	b=V0*sin(alpha);
	c=h0;

	*timpact=polynome(a,b,c);
	*d=V0*cos(alpha)**timpact;
    
	*Vimpact=pow( pow(V0*cos(alpha),2) + pow(V0*sin(alpha)-PESANTEUR**timpact,2) , 0.5);
}

int main (int argc, char*argv[])
{
	double V0,alpha,h0;
	double tmax,ymax,timpact,d,Vimpact;
	printf("Veuillez indiquer la vitesse v0, l'angle alpha puis la hauteur initiale h0\n");
	scanf("%lf""%lf""%lf",&V0,&alpha,&h0);
	alpha=alpha*(PI/180);
	balistique(V0,alpha,h0,&tmax,&ymax,&timpact,&d,&Vimpact);
	printf("La hauteur maximale atteinte est %lf et est atteinte a t=%lf\n",ymax,tmax);
	printf("La portee est de %lf, est atteinte a t=%lf et a une vitesse V=%lf",d,timpact,Vimpact);
}
