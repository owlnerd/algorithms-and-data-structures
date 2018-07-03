#include "../include/dlist-node.h"
#include <stdlib.h>
/*
    NODE FOR DOUBLY LINKED LIST DATASTRUCTURE
    -----------------------------------------
    Struct itself is defined in the header file. Create defined below.
*/


/*  Creates and returns a new DLIST_NODE with data field populated by e  */
DLIST_NODE *create_dlist_node(int k, int d)
{
    DLIST_NODE *dn = (DLIST_NODE*)malloc(sizeof(DLIST_NODE));;
    dn->key = k;
    dn->dat = d;
    dn->next = NULL;
    dn->prev = NULL;
    return dn;
}