#ifndef DLISTNODE_H_INCLUDED
#define DLISTNODE_H_INCLUDED


/*
    DOUBLY LINKED LIST NODE structure
    ---------------------------------
    Struct fields include data of type int and two pointers to
    DLIST_NODE elements, one for previous and one for next element.
    Field key holds the node key.
*/
typedef struct dlist_node {
    int key;
    int dat;
    struct dlist_node *prev;
    struct dlist_node *next; 
} DLIST_NODE;


DLIST_NODE *create_dlist_node(int, int);


#endif