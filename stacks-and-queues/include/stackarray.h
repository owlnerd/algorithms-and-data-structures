#ifndef STACKARRAY_H_INCLUDED
#define STACKARRAY_H_INCLUDED

/*
    STACK_ARRAY structure
    ---------------------
    Stack is implemented as an array. Capacity of the stackarray is len.
    Index of the top of the stack is contained in the top member value.
*/ 
typedef struct {
    int top;
    int len;
    int *array;
} STACK_ARRAY;

STACK_ARRAY new_stacka(int);
int stacka_empty(STACK_ARRAY);
int stacka_full(STACK_ARRAY);
void stacka_push(STACK_ARRAY, int);
void stacka_pop(STACK_ARRAY*, int*);
void print_stacka(STACK_ARRAY);

#endif