#include "../include/nsqsorts.h"
#include "../include/nlognsorts.h"
#include "../include/helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FUNC_NUM 5


int main()
{
    /*
        Array of FUNC objects to hold references to sorting algorithm
        functions and their names
    */
    FUNC funcs[FUNC_NUM];
    funcs[0].func = bubble_sort;    strcpy(funcs[0].name, "Bubble sort");
    funcs[1].func = selection_sort; strcpy(funcs[1].name, "Selection sort");
    funcs[2].func = insertion_sort; strcpy(funcs[2].name, "Insertion sort");
    funcs[3].func = quick_sort;     strcpy(funcs[3].name, "Quick sort");
    funcs[4].func = merge_sort;     strcpy(funcs[4].name, "Merge sort");

    int *a, n;

    printf("Input array length >> ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    initialize_array(a, n);
    execute_sorts(funcs, FUNC_NUM, a, n);
    free(a);

    return EXIT_SUCCESS;
}