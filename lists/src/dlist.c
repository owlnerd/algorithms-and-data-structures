#include "../include/dlist-node.h"
#include "../include/dlist.h"
#include <stdio.h>
/*
    DOUBLY LINKED LIST DATASTRUCTURE
    --------------------------------
    Struct is defined in the header file. Operations defined below.
*/


/*  Creates a new doubly linked list and returns a pointer to it. Newly
    created list lives on the heap.  */
DLIST *create_dlist()
{
    DLIST *dl = (DLIST*)malloc(sizeof(DLIST));
    dl->a_key = -1;
    dl->head = NULL;
    dl->tail = NULL;
    dl->cursor = NULL;
    return dl;
}


/*  If cursori is in place, ANY insertion or delition operation performed on
    the list will reset the cursor. In no cursor is in place, cursor member
    will hold NULL value.  */
void dlist_reset_cursor(DLIST* dlist)
{
    dlist->cursor = NULL;
}


/*  Checks if the list is empty (not containing any node).
    If empty, returns 1, 0 otheriwise.  */
int dlist_empty(DLIST *dl)
{
    if (dl->head == NULL)
        return 1;
    return 0;
}


/*  Returns a pointer to the node with the passed key value  */
DLIST_NODE *dlist_search_key(DLIST *dlist, int key)
{
    if (dlist_empty(dlist))
        return NULL;
    DLIST_NODE *current_node = dlist->head;
    while (current_node != NULL && current_node->key != key) {
        current_node = current_node->next;
    }
    return current_node;
}


/*  Inserts a new node into the list. Newly inserted node occupies the
    position of the head of the list.  */
void dlist_head_insert(DLIST *dlist, int data)
{
    DLIST_NODE *new_node = create_dlist_node(++(dlist->a_key), data);
    if (dlist_empty(dlist)) {
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        dlist->head->prev = new_node;
        new_node->next = dlist->head;
        dlist->head = new_node;
        dlist_reset_cursor(dlist);
    }
}


/*  Inserts a new node into the list. Newly inserted node occupies the
    position of the tail of the list.  */
void dlist_tail_insert(DLIST *dlist, int data)
{
    DLIST_NODE *new_node = create_dlist_node(++(dlist->a_key), data);
    if (dlist_empty(dlist)) {
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        new_node->prev = dlist->tail;
        dlist->tail->next = new_node;
        dlist->tail = new_node;
        dlist_reset_cursor(dlist);
    }
}


/*  Inserts a new node into the list. Newly inserted node occupies the
    position one place AFTER the position of the node with the key value
    of the passed key parameter.  */
void dlist_key_insert(DLIST *dlist, int key, int data)
{
    DLIST_NODE *key_node = dlist_search_key(dlist, key);
    if (key_node == NULL)
        return;
    else {
        if (key_node == dlist->tail)
            dlist_tail_insert(dlist, data);
        else {
            DLIST_NODE *new_node = create_dlist_node(++(dlist->a_key), data);
            new_node->next = key_node->next;
            new_node->prev = key_node;
            key_node->next = new_node;
        }
        dlist_reset_cursor(dlist);
    }
}


/*  Deletes the node which currently occupies the head of the list. Heap
    space that deleted node occupied also gets deallocated.  */
void dlist_head_delete(DLIST *dlist)
{
    if (!dlist_empty(dlist)) {
        DLIST_NODE *old_head = dlist->head;
        dlist->head = dlist->head->next;
        dlist->head->prev = NULL;
        free(old_head);
        dlist_reset_cursor(dlist);
    }
}


/*  Deletes the node which currently occupies the tail of the list. Heap
    space that deleted node occupied also gets deallocated.  */
void dlist_tail_delete(DLIST *dlist)
{
    if (!dlist_empty(dlist)) {
        DLIST_NODE *old_tail = dlist->tail;
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;
        free(old_tail);
        dlist_reset_cursor(dlist);
    }
}


/*  Deletes the node with the key value of the passed parameter. */
void dlist_key_delete(DLIST *dlist, int key)
{
    DLIST_NODE *key_node = dlist_search_key(dlist, key);
    if (key_node != NULL)
        if (key_node == dlist->head)
            dlist_head_delete(dlist);
        else if (key_node == dlist->tail)
            dlist_tail_delete(dlist);
        else {
            key_node->prev->next = key_node->next;
            key_node->next->prev = key_node->prev;
            free(key_node);
            dlist_reset_cursor(dlist);
        }
}


/*  Returns the node on which the cursor is currently possitioned.  */
DLIST_NODE *get_current_node(DLIST *dlist)
{
    if (dlist->cursor == NULL) return NULL;
    return dlist->cursor;
}


/*  Moves the list cursor to the next list node and returns a pointer to that
    node. If no cursor is currently in place, sets new cursor to head
    list element and returns the pointer to cursor. If cursor is currently
    pointing to tail element, resets the cursor and returns NULL.  */
DLIST_NODE *get_next_node(DLIST *dlist)
{
    if (dlist->cursor == NULL) {
        dlist->cursor = dlist->head;
        return dlist->cursor;
    }
    if (dlist->cursor == dlist->tail) {
        return dlist->cursor = NULL;
    }
    dlist->cursor = dlist->cursor->next;
    return dlist->cursor;

}


/*  Moves the list cursor to the previous list node and returns a pointer to
    that node. If no cursor is currently in place, sets new cursor to tail
    list element and returns the pointer to cursor. If cursor is currently
    pointing to head element, resets the cursor and returns NULL. */
DLIST_NODE *get_prev_node(DLIST *dlist)
{
    if (dlist->cursor == NULL) {
        dlist->cursor = dlist->tail;
        return dlist->cursor;
    }
    if (dlist->cursor == dlist->head)
        return dlist->cursor = NULL;
    return dlist->cursor = dlist->cursor->prev;
}


/*  Returns the number of nodes currently in the list. */
int dlist_count_nodes(DLIST *dlist)
{
    DLIST_NODE *cursor = dlist->head;
    int i = 0;
    while (cursor != NULL) {
        cursor = cursor->next;
        i++;
    }
    return i;
}


/*  Swaps positions of two nodes in the list  */
void dlist_swap_nodes(DLIST *dlist, DLIST_NODE *a, DLIST_NODE *b)
{
/*  TO BE IMPLEMENTED  */
}


/*  Sorts the list based on key value using insertion sort algorithm.
    For the purpose of simplicity, only non descending sort is performed.  */
void dlist_sort_key(DLIST *dlist)
{
/*  TO BE IMPLEMENTED  */
}


/*   Sorts the list based on data value using selection sort algorithm.
     For the purpose of simplicity, only non descending sort is performed.  */
void dlist_sort_data(DLIST *dlist)
{
/*  TO BE IMPLEMENTED  */
}


/*  Prints the list passed as argument. Node upon which the cursor is
    positioned is marked by '^' character.  */
void dlist_print(DLIST *dlist)
{
    DLIST_NODE *cursor = dlist->head;
    while (cursor != NULL) {
        printf("-[");
        if (cursor == dlist->cursor)
            putchar('^');
        printf("%d:%d]-", cursor->key, cursor->dat);
        cursor = cursor->next;
    }
    putchar('\n');
}


/*  Deallocates all heap space allocated to the list, effectively destroying
    the list.  */
void dlist_destroy(DLIST* dlist)
{
    if (dlist->head != NULL) free(dlist->head);
    if (dlist->tail != NULL) free(dlist->tail);
    if (dlist->cursor != NULL) free(dlist->cursor);
    free(dlist);
}