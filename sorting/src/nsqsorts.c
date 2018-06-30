#include "../include/nsqsorts.h"
#include "../include/helpers.h"
/*
    NSQSORTS - Algorithms for sorting in O(n^2)
    -------------------------------------------
    Includes:
     - Bubble sort
     - Selection sort
     - Insertion sort
    -------------------------------------------
    For simplicity reasons, implemented algorithms operate exclusivelly
    on arrays of integers, and sort in non descending order.
*/


/*
    BUBBLE SORT
*/
void bubble_sort(int *a, int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}


/*
    SELECTION SORT
*/
void selection_sort(int *a, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (min != i)
            swap(&a[i], &a[min]);
    }
}


/*
    INSERTION SORT
*/
void insertion_sort(int *a, int n)
{
    int i, j;

    for (i = 1; i < n; i++) {
        int ins = a[i];
        for (j = i - 1; j >= 0 && a[j] > ins; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = ins;
    }
}