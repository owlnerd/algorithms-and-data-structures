#ifndef QUESUARRAY_H_INCLUDED
#define QUEUEARRAY_H_INCLUDED
/*
    QUEUE_ARRAY structure
    ---------------------
    Queue is implemented as an array. Capacity of the queue is len - 1.
    Index of the oldest element in the queue is contained in the head
    member variable, index position of the newest item is the value of
    tail member variable minus 1.
*/ 

typedef struct {
    int head;
    int tail;
    int len;
    int *array;    
} QUEUE_ARRAY;

QUEUE_ARRAY new_queue_array(int);
int queuea_full(QUEUE_ARRAY);
int queuea_empty(QUEUE_ARRAY);
void queuea_enqueue(QUEUE_ARRAY*, int);
int queuea_dequeue(QUEUE_ARRAY*, int*);
void print_queuea(QUEUE_ARRAY);

#endif