#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MASSE 0.1
#define BETA 0.5
#define GRAVITE 9.806

double dvdt(double v)   //Calcule la derivee de la vitesse par rapport au temps.
{
    double res = ( (MASSE * GRAVITE) - (BETA * v * v) ) / MASSE;
    return res;
}

void remplissage_temps(double *tab,double TailleTab,double DeltaT)  //Rempli le tableau des abscisses (interval deltaT)
{
    for (int i=0;i<TailleTab;i++)
    {
        tab[i]=i*DeltaT;
    }
}

void remplissage_vitesse(double *tab,double TailleTab,double DeltaT)    //Rempli le tableau des ordonnées (inter al deltaT)
{
    tab[0]=0.0;
    for (int i=0;i<TailleTab;i++)
    {
        tab[i+1] = tab[i] + DeltaT * dvdt(tab[i]);
    }
}

void remplissage_fichier(double *temps, double *vitesse, double TailleTab)  //Rempli le fichier csv avec la vitesse en fonction du temps
{
    FILE *Graph;
    Graph = fopen("Graph.csv","w+");
    if(Graph != NULL)
    {
        for(int i=0;i<TailleTab;i++)
        {
            fprintf(Graph,"%f;%f\n",temps[i],vitesse[i]);
        }
    }
    else
    {
        printf("Erreur");
    }
    fclose(Graph);
}

int main ()
{
    double TailleTab,TempsMaxIntegration, DeltaT;
    printf("Choisis la taille du tableau\n");
    scanf("%lf",&TailleTab);
    printf("Choisis le temps maximal d'integration\n");
    scanf("%lf",&TempsMaxIntegration);
    DeltaT = TempsMaxIntegration / TailleTab;   //Calcul du DeltaT

    //Allocation memoire des tableaux necessaires
    double *temps;
    temps = malloc(TailleTab*sizeof(double));
    double *vitesse;
    vitesse = malloc(TailleTab*sizeof(double));

    //Appel des fonctions
    remplissage_temps(temps,TailleTab,DeltaT);
    remplissage_vitesse(vitesse,TailleTab,DeltaT);
    remplissage_fichier(temps,vitesse,TailleTab);

    //Liberation de la memoire
    free(temps);
    free(vitesse);

    return 0;
}