#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "util.h"
#define getName(var) #var

void selectionSort(int tab[], int N)
// The idea is to loop through the array, find the smallest element and swap it with the first element. And keep going until the end.
{
    int i, j;               // Loop indexes
    int min_index;          // Index of the smallest element
    int temp;               // Temp element used for swapping
    for (i = 0; i < N; i++) // We loop through the array
    {
        min_index = i;              // We set the min_index to the current index
        for (j = i + 1; j < N; j++) // We loop through the rest of the array
        {
            if (tab[j] < tab[min_index]) // If we find a smaller element
            {
                min_index = j; // We set the min_index to the index of the smaller element
            }
        }
        // We swap the current element with the smallest element
        temp = tab[i];
        tab[i] = tab[min_index];
        tab[min_index] = temp;
    }
}

void insertionSort(int tab[], int N)
// The idea is that we're going through the array and we're inserting the current element in the right place in the sorted part of the array. (left)
{
    int i, j;               // Loop indexes
    int temp;               // Temp element used for swapping
    for (i = 1; i < N; i++) // We loop through the array, starting from the second element
    {
        temp = tab[i];                  // We store the current element
        j = i - 1;                      // We set the j index to the previous element
        while (j >= 0 && tab[j] > temp) // While we're not at the beginning of the array and the previous element is bigger than the current element
        {
            tab[j + 1] = tab[j]; // We move the previous element to the right
            j = j - 1;           // We move the j index to the left
        }
        tab[j + 1] = temp; // We insert the current element in the right place
    }
}

void bubbleSort(int tab[], int N)
// The idea is to loop through the array and swap the current element with the next one if it's bigger.
{
    for (int i = 0; i < N; i++) // We loop through the array
    {
        for (int j = 0; j < N - i - 1; j++) // We loop through the array, minus the elements that are already sorted
        {
            if (tab[j] > tab[j + 1]) // If the current element is bigger than the next one
            {
                // We swap the two elements
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;             // Loop indexes
    int n1 = mid - left + 1; // Number of elements in the first subarray
    int n2 = right - mid;    // Number of elements in the second subarray

    int L[n1], R[n2]; // We create two temporary arrays

    // We fill the temporary arrays

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // We merge the two temporary arrays back into arr[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) // If the element in the first subarray is smaller than the element in the second subarray
        {
            arr[k] = L[i]; // We put the element in the merged array
            i++;           // Don't forget to increment the index
        }
        else // Else we put the element of the second subarray in the merged array
        {
            arr[k] = R[j]; // We put the element in the merged array
            j++;           // Don't forget to increment the index
        }
        k++;
    }

    // We copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // We copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
// The idea is to split the array in two parts, sort them and merge them.
// Superb explanation : https://www.youtube.com/watch?v=IJDJ0kBx2LM&feature=youtu.be
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // We find the middle of the array

        // We sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // We merge two subarrays
        merge(arr, left, mid, right);
    }
}

int main(int argc, char *argv[])
{
    // Variables declarations
    int N = 1000;

    // Selection Sort
    int selection_tab[N];
    clock_t selection_start, selection_end;
    // Tabs generation
    randomizeTab(selection_tab, N);
    printf("Table : %s \n", getName(selection_tab));
    printTab(selection_tab, N);
    // Execution on the sorting algorithm
    selection_start = clock();
    selectionSort(selection_tab, N);
    selection_end = clock();
    // Print results
    printf("Ordered table : %s \n", getName(selection_tab));
    printTab(selection_tab, N);

    // Insertion Sort
    int insertion_tab[N];
    clock_t insertion_start, insertion_end;
    // Tabs generation
    randomizeTab(insertion_tab, N);
    printf("Table : %s \n", getName(insertion_tab));
    printTab(insertion_tab, N);
    // Execution on the sorting algorithm
    insertion_start = clock();
    insertionSort(insertion_tab, N);
    insertion_end = clock();
    // Print results
    printf("Ordered table : %s \n", getName(insertion_tab));
    printTab(insertion_tab, N);

    // Bubble Sort
    int bubble_tab[N];
    clock_t bubble_start, bubble_end;
    // Tabs generation
    randomizeTab(bubble_tab, N);
    printf("Table : %s \n", getName(bubble_tab));
    printTab(bubble_tab, N);
    // Execution on the sorting algorithm
    bubble_start = clock();
    bubbleSort(bubble_tab, N);
    bubble_end = clock();
    // Print results
    printf("Ordered table : %s \n", getName(bubble_tab));
    printTab(bubble_tab, N);

    // Merge Sort
    int merge_tab[N];
    clock_t merge_start, merge_end;
    // Tabs generation
    randomizeTab(merge_tab, N);
    printf("Table : %s \n", getName(merge_tab));
    printTab(merge_tab, N);
    // Execution on the sorting algorithm
    merge_start = clock();
    mergeSort(merge_tab, 0, N - 1);
    merge_end = clock();
    // Print results
    printf("Ordered table : %s \n", getName(merge_tab));
    printTab(merge_tab, N);

    // Time results
    printf("Time taken by Selection Sort: %f s\n", ((double)(selection_end - selection_start)) / CLOCKS_PER_SEC);
    printf("Time taken by Insertion Sort: %f s\n", ((double)(insertion_end - insertion_start)) / CLOCKS_PER_SEC);
    printf("Time taken by Bubble Sort: %f s\n", ((double)(bubble_end - bubble_start)) / CLOCKS_PER_SEC);
    printf("Time taken by Merge Sort: %f s\n", ((double)(merge_end - merge_start)) / CLOCKS_PER_SEC);

    return 0;
}