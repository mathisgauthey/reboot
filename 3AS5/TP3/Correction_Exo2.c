#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void avion(double rho, double V, double S, double T, double alpha, double *Portance, double *Trainee, double *Finesse)
{
	double Tx,Tz;
	Tx=T*cos(alpha);
	Tz=T*sin(alpha);
	*Trainee=Tx/(0.5*rho*V*V*S);
	*Portance=Tz/(0.5*rho*V*V*S);
	*Finesse = *Portance / *Trainee;
}

int main (int argc, char*argv[])
{
	double rho,V,S,T,alpha,Portance,Trainee,Finesse;
	printf("Choisir la masse volumique rho \n");
	scanf("%lf",&rho);
	printf("Choisir la vitesse V \n");
	scanf("%lf",&V);
	printf("Choisir le maitre couple S \n");
	scanf("%lf",&S);
	printf("Choisir la force T \n");
	scanf("%lf",&T);
	printf("Choisir l'angle alpha \n");
	scanf("%lf",&alpha);
	avion(rho,V,S,T,alpha,&Portance,&Trainee,&Finesse);
	printf("La portance vaut %lf \nLa trainee vaut %lf \nLa finesse vaut %lf \n",Portance,Trainee,Finesse);
}
