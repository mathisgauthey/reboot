#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void initialisation_statique(int tab[],int n)
{
    for (int i=0;i<n;i++)
    {
        tab[i]=0;
    }
}

void affichage_statique(int tab[],int n)
{
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("%d     ",tab[i]);
    }
    printf("\n\n");
}

void remplissage_statique(int tab[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("Selectionnez la %d eme case du tableau: ",i);
        scanf("%d",&tab[i]);
    }
}

void somme_statique(int tab1[],int tab2[],int tab3[],int n)
{
    for(int i=0;i<n;i++)
    {
        tab3[i] = tab1[i] + tab2[i];
    }
}

void tri_decroissant_statique(int tab[],int n)
{
    int roulement;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(tab[j]<tab[j+1])
            {
                roulement = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = roulement;
            }
        }
    }
}

void affichage_dynamique(int *tab, int n)
{
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("%d     ",tab[i]);
    }
    printf("\n\n");
}

int factorielle(int facto)
{
    int res=1;
    for(int i=2;i<facto;i++)
    {
        res = i*res;
    }
    return res;
}

void remplissage_facto(int *tab, int n)
{
    for (int i=0;i<n;i++)
    {
        tab[i] = factorielle(i);
    }
}

int main ()
{
    int N;
    printf("Choisis un N stp mec\n");
    scanf("%d",&N);
    int *tab;
    tab = malloc(N*sizeof(int));
    remplissage_facto(tab,N);
    affichage_dynamique(tab,N);
    free(tab);
}