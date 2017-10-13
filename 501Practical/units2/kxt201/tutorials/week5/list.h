/*  list.h - Mike Cameron-Jones - 4/02/03
    (based upon own C program from past first year unit)
    
    This is just the header file for the functions implemented in list.c

    It illustrates the use of #ifndef and #define that prevents the definitions
    being included twice when the file itself is included twice by mistake.

    Unlike Weiss's list header file, this one includes the definition of the 
    node struct type. Weiss's approach might be better in terms of
    encapsulation.
*/

#ifndef _LIST_H
#define _LIST_H

/* Define node and node_ptr type */
typedef struct node *node_ptr;
struct node
{
    int data_item;
    node_ptr next;
};

/* Function to create an empty list */
node_ptr create(void);

/* Function to return dynamically allocated memory in list */
void destroy(node_ptr list);

/* Function to insert n at front of list */
void insert_at_front(int n, node_ptr list);

/* Function to print list */
void print(node_ptr list);

/* Function to insert n in (non-decreasing) order in list - assuming list 
   items are already in (non-decreasing) order. */
void insert_in_order(int n, node_ptr list);

#endif
