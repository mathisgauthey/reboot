#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void randomizeTab(int tab[], int N)
{
    for (int i = 0; i < N; i++)
    {
        tab[i] = rand() % 100;
    }
}

void printTab(int tab[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", tab[i]);
    }
}

void sumTabs(int tab1[], int tab2[], int tab3[], int N)
{
    for (int i = 0; i < N; i++)
    {
        tab3[i] = tab1[i] + tab2[i];
    }
}

void orderTab(int tab[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int N = 10;
    int tab1[N];
    int tab2[N];
    int tab3[N];
    int tab4[N];
    randomizeTab(tab1, N);
    randomizeTab(tab2, N);
    printf("This is tab 1 : \n");
    printTab(tab1, N);
    printf("This is tab 2 : \n");
    printTab(tab2, N);
    sumTabs(tab1, tab2, tab3, N);
    printf("This is tab 3 : \n");
    printTab(tab3, N);
    randomizeTab(tab4, N);
    printf("This is tab 4 : \n");
    printTab(tab4, N);
    orderTab(tab4, N);
    printf("This is tab 4, but organized in ascending order : \n");
    printTab(tab4, N);
    return 0;
}