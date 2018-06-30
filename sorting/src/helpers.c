#include "../include/helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void initialize_array(int *a, int n)
{
    srand((unsigned)time(NULL));
    int i, scope = 2 * n;

    for (i = 0; i < n; i++)
        a[i] = rand() % scope;
}


void print_array(int *a, int n)
{
    int i;

    printf("[ ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");
}


void copy_array(int *a, int *b, int n)
{
    int i;

    for (i = 0; i < n; i++) a[i] = b[i];
}


void execute_sorts(FUNC *functions, int nf, int *a, int na)
{
    int *tmp = (int*)malloc(na * sizeof(int));
    int i;
    
    for (i = 0; i < nf; i++) {
        copy_array(tmp, a, na);
        printf("%s\n==========\n", functions[i].name);
        printf("Initial array: ");
        print_array(tmp, na);
        (*functions[i].func)(tmp, na);
        printf("Sorted array:  ");
        print_array(tmp, na);
        putchar('\n');
    }
    free(tmp);
}