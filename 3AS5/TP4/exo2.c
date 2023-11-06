#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void printTab(int *tab, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", tab[i]);
    }
}

void factoTab(int *tab, int N)
{

    tab[0] = 1;
    tab[1] = 1;
    for (int i = 2; i < N; i++)
    {
        tab[i] = tab[i - 1] * i;
    }
}

int main(int argc, char *argv[])
{
    int N;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    int *tab = NULL;
    tab = malloc(N * sizeof(int));
    factoTab(tab, N);
    printTab(tab, N);
    free(tab);
    return 0;
}

// EXPLICATION OF MALLOC

// You're correct that you can use a statically allocated array like `int tab[N]` when you know the size of the array at compile time. In that case, dynamic allocation with `malloc` is not necessary. The primary advantage of dynamic memory allocation with `malloc` is that it allows you to allocate memory at runtime when you don't know the size of the array in advance or when you want to allocate a large amount of memory that might not fit on the stack.

// If you know the size of the array at compile time and it's a fixed value, you can use a statically allocated array like this:

// ```c
// int tab[N];
// ```

// This way, the memory for the array is allocated on the stack, and you don't need to worry about explicitly freeing it because it's automatically deallocated when the function in which it's defined exits.

// Dynamic allocation with `malloc` is more flexible and suitable when you need to allocate memory dynamically based on user input, data from external sources, or when the size of the array is not known until runtime. Statically allocated arrays are more efficient for small, fixed-size arrays, but they may not be suitable for larger or dynamically sized arrays.

// In your original code, you used dynamic allocation with `malloc`, which is perfectly fine if you want to practice dynamic memory management, but it's not necessary when you have a fixed size known at compile time. Using `int tab[N]` is simpler and more efficient in such cases.