#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double tempstotal(double Ya,double Xc,double Xb,double Yb,double Vplage,double Vmer)
{
	double T;
	T = sqrt(Ya*Ya+Xc*Xc)/Vplage + sqrt((Xb-Xc)*(Xb-Xc)+Yb*Yb)/Vmer;
	return T;
}

double toSolve(double Ya,double Xc,double Xb,double Yb,double Vplage,double Vmer)
{
	double dT;
	dT = 1.0 / ( Vplage * sqrt( (Ya/Xc)*(Ya/Xc) + 1.0) ) + (Xc-Xb) / ( Vmer * sqrt( (Xb-Xc)*(Xb-Xc) + Yb*Yb) );
	return dT;
}

double resolution(double Ya,double Xb,double Yb,double Vplage,double Vmer,double erreurmax,double *residu,int *iteration)
{
	double Xg=0.0, Xd=Xb,Xc;

	do
	{
		Xc = Xd - toSolve(Ya,Xd,Xb,Yb,Vplage,Vmer) * ( (Xd-Xg) / ( toSolve(Ya,Xd,Xb,Yb,Vplage,Vmer) - toSolve(Ya,Xg,Xb,Yb,Vplage,Vmer) ) );
		*residu = fabs(toSolve(Ya,Xc,Xb,Yb,Vplage,Vmer));
		if (toSolve(Ya,Xc,Xb,Yb,Vplage,Vmer)*toSolve(Ya,Xd,Xb,Yb,Vplage,Vmer) < 0.0)
		{
			Xg=Xc;
		}
		if (toSolve(Ya,Xc,Xb,Yb,Vplage,Vmer)*toSolve(Ya,Xg,Xb,Yb,Vplage,Vmer) < 0.0)
		{
			Xd=Xc;
		}
		*iteration+=1;
	} while (*residu > erreurmax);
	
	return Xc;
}

int main (int argc, char*argv[])
{
	double Ya,Xb,Yb,Xc,Vplage,Vmer,erreurmax,residu=0.0;
	int iteration=0;
	printf("Veuillez choisier Ya \n");
	scanf("%lf",&Ya);
	printf("Veuillez choisier Xb \n");
	scanf("%lf",&Xb);
	printf("Veuillez choisier Yb \n");
	scanf("%lf",&Yb);
	printf("Veuillez choisier Vplage \n");
	scanf("%lf",&Vplage);
	printf("Veuillez choisier Vmer \n");
	scanf("%lf",&Vmer);
	printf("Veuillez choisier erreurmax \n");
	scanf("%lf",&erreurmax);
	Xc=resolution(Ya,Xb,Yb,Vplage,Vmer,erreurmax,&residu,&iteration);
	printf("La solution est Xc=%lf \nLe procede a requis %d iterations et l'erreur finale est de %.16lf",Xc,iteration,residu);
	return 0;
}
