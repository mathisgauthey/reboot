#include <stdlib.h>
#include <stdio.h>

float contraintocalculum(float Young,float eps)
{
    float sigma;
    sigma=Young*eps;
    return sigma;
}

float deformatiocalculum(float sigma,float Young)
{
    float eps;
    eps=sigma/Young;
    return eps;
}

int main (int argc, char*argv[])
{
    float contrainte=0.0,moduleY=0.0,epsilon=0.0;
    int choix;
    while (choix!=1 && choix!=2)
    {
        printf("Que voulez vous calculer ? La contrainte d'un materiaux [1] ou la deformation [2] ?\n");
        scanf("%d",&choix);
    }
    if(choix==1)
    {
        printf("Ok super on va calculer la contrainte. Donne moi le module d'Young de ton materiaux puis le taux de déformation donné \n");
        scanf("%f""%f",&moduleY,&epsilon);
        printf("La contrainte vaut %f \n",contraintocalculum(moduleY,epsilon));
    }
    else
    {
        printf("Ok super on va calculer la deformation. Donne moi la contraite puis le module d'young de ton matériaux \n");
        scanf("%f""%f",&contrainte,&moduleY);
        printf("La deformation vaut %f \n",deformatiocalculum(contrainte,moduleY));
    }
    return 0;
}
