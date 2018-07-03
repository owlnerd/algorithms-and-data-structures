#include "../include/stackarray.h"
/*
    STACK DATASTRUCTURE - ARRAY IMPLEMENTATION
    ------------------------------------------
    Struct itself is defined in the header file. Operations are defined below.
*/


/*  Creates and returns a new stack with capacity n  */
STACK_ARRAY new_stacka(int n)
{
    STACK_ARRAY s;

    s.top = -1;
    s.len = n;
    s.array = (int*)malloc(n * sizeof(int));

    return s;
}


/*  Checks if the stack is empty  */
int stacka_empty(STACK_ARRAY s)
{
    if (s.top < 0)
        return 1;
    return 0;
}


/*  Checks if the stack is full  */
int stacka_full(STACK_ARRAY s)
{
    if (s.top == s.len - 1)
        return 1;
    return 0;
}


/*  Pushes an element e onto stack s  */
void stacka_push(STACK_ARRAY *s, int e)
{
    if (!stack_array_full(*s))
        s->array[++(s->top)] = e;
}


/*  Pops an element from stack and loads it into the variable pointed to
    by ret pointer  */
void stacka_pop(STACK_ARRAY *s, int *ret)
{
    if (!stack_array_empty(*s))
        *ret = s->array[s->top--];
}


/*  Prints the stack to stdout  */
void print_stacka(STACK_ARRAY s)
{
    int i;

    printf("|| ");
    for (i = 0; i <= s.top; i++)
        printf("%d ", s.array[i]);
    printf("||\n");
}