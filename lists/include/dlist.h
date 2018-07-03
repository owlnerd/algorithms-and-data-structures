#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
#include "dlist-node.h"

/*
    DOUBLY LINKED LIST structure
    ----------------------------
    Struct fields contain DLIST_NODE pointers to list head and tail.
*/
typedef struct dlist{
    int a_key;
    DLIST_NODE *head;
    DLIST_NODE *tail;
    DLIST_NODE *cursor;
} DLIST;


DLIST *create_dlist();
void dlist_reset_cursor(DLIST*);
int dlist_empty(DLIST*);
DLIST_NODE *dlist_search_key(DLIST*, int);
void dlist_head_insert(DLIST*, int);
void dlist_tail_insert(DLIST*, int);
void dlist_key_insert(DLIST*, int, int);
void dlist_head_delete(DLIST*);
void dlist_tail_delete(DLIST*);
void dlist_key_delete(DLIST*, int);
DLIST_NODE *get_current_node(DLIST*);
DLIST_NODE *get_next_node(DLIST*);
DLIST_NODE *get_prev_node(DLIST*);
int dlist_count_nodes(DLIST*);
void dlist_swap_nodes(DLIST*, DLIST_NODE*, DLIST_NODE*);
void dlist_sort_key(DLIST*);
void dlist_sort_data(DLIST*);
void dlist_print(DLIST*);
void dlist_destroy(DLIST*);

#endif