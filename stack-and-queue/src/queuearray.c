#include "../include/queuearray.h"
/*
    QUEUE DATASTRUCTURE - ARRAY IMPLEMENTATION
    ------------------------------------------
    Struct itself is defined in the header file. Functions are defined below.
*/


/*  Creates and returns a new queue with capacity n - 1  */
QUEUE_ARRAY new_queue_array(int n)
{
    QUEUE_ARRAY q;

    q.head = q.tail = 0;
    q.len = n;
    q.array = (int*)malloc(n * sizeof(int));

    return q;
}


/*  Checks if the queue is full  */
int queuea_full(QUEUE_ARRAY qa)
{
    if (qa.head == qa.tail + 1 || (qa.head == 0 && qa.tail == qa.len - 1))
        return 1;
    return 0;
}


/*  Checks if the queue is empty  */
int queuea_empty(QUEUE_ARRAY qa)
{
    if (qa.head == qa.tail)
        return 1;
    return 0;
}


/*  Puts a new element w into the queue  */
void queuea_enqueue(QUEUE_ARRAY *qa, int w)
{
    if (!queuea_full(*qa)) {
        qa->array[qa->tail] = w;
        if (qa->tail == qa->len - 1)
            qa->tail = 0;
        else
            qa->tail++;
    }
}


/*  Removes the oldest element in the queue and loadst it into the variable
    pointed to by the ret pointer  */
int queuea_dequeue(QUEUE_ARRAY *qa, int *ret)
{
    if (!queuea_empty(*qa)) {
        *ret = qa->array[qa->head];
        if (qa->head == qa->len - 1)
            qa->head = 0;
        else
            qa->head++;
    }
}


/*  Prints the queue  */
void print_queuea(QUEUE_ARRAY qa)
{
    int i = qa.head;

    printf("-> ");
    while (i != qa.tail) {
        printf("%d ", qa.array[i]);
        if (i == qa.len - 1)
            i = 0;
        else
            i++;
    }
    printf("->\n");
}