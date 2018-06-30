#include "../include/nlognsorts.h"
#include "../include/helpers.h"
#include <stdlib.h>
/*
    NLOGNSORTS - Algorithms for sorting in O(nlog(n))
    -------------------------------------------------
    Includes:
     - Quick sort
     - Merge sort
     - Heap sort (to be implemented)
    -------------------------------------------------
    For simplicity reasons, implemented algorithms operate exclusivelly
    on arrays of integers, and sort in non descending order.
*/


/*
    QUICK SORT - wrapper function, so I can call quick sort supplying only
    array and length, instead of array, lower and upper bound.
*/    
void quick_sort(int *a, int n)
{
    q_sort(a, 0, n - 1);
}


/*
    QUICK SORT - actual algorithm.
*/    
void q_sort(int *a, int l, int u)
{
    if (l >= u) return;
    int pivot = (l + u) / 2;
    int k, i;

    swap(&a[l], &a[pivot]);
    k = pivot = l;
    for (i = l; i <= u; i++)
        if (a[pivot] > a[i])
            swap(&a[++k], &a[i]);
    swap(&a[pivot], &a[k]);

    q_sort(a, l, k - 1);
    q_sort(a, k + 1, u);
}


/*
    MERGE SORT - wrapper function, so I can call merge sort supplying only
    array and length, instead of array, lower and upper bound.
*/   
void merge_sort(int *a, int n)
{
    m_sort(a, 0, n - 1);
}


/*
    MERGE SORT - actual algorithm.
*/  
void m_sort(int *a, int l, int u)
{
    if (l >= u) return;
    int mid = (l + u) / 2;
    
    m_sort(a, l, mid);
    m_sort(a, mid + 1, u);
    merge(a, l, mid, u);
}


/*
    MERGE helper function - executes merging of two sorted arrays.
*/
void merge(int *a, int l, int mid, int u)
{
    int *tmp = (int*)malloc((u - l + 1)  * sizeof(int));
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= u)
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= u)
        tmp[k++] = a[j++];
    
    for (i = l, k = 0; i <= u; i++, k++)
        a[i] = tmp[k];

    free(tmp);
}