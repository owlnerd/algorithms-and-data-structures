#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

/*
    FUNC structure. Holds:
     - pointer to a function that takes one pointer to an integer and
       one integer as arguments and returns void.
     - character string that holds the name of the function that the
       func pointer points to.
*/
typedef struct {
    void (*func)(int*, int);
    char name[15];
} FUNC;

void swap(int*, int*);
void initialize_array(int*, int);
void print_array(int*, int);
void copy_array(int*, int*, int);
void execute_sorts(FUNC*, int, int*, int);

#endif