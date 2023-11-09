#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "util.h"

void printTab(int tab[], int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", tab[i]);
    }
}

void randomizeTab(int tab[], int N)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        tab[i] = rand() % 1000;
    }
}