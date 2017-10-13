/*  list.c - Mike Cameron-Jones - 4/02/03
    (based upon own C program from past first year unit)
    
    This code illustrates the use of pointers to implement a linked list,
    with a dummy header node. The last node's next will be NULL. (The use of
    the dummy header node simplifies some of the code as it ensures that there
    is always a node before every node containing an item, even the first
    one.)
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Function to create an empty list 
   (the void argument list indicates that it takes no arguments) */
node_ptr create(void)
{
    node_ptr list = (node_ptr) malloc(sizeof(struct node));
    list->data_item = 0; /* superfluous initialisation */
    list->next = NULL; /* necessary initialisation to indicate last node */
    return list;
}

/* Function to return dynamically allocated memory in list */
void destroy(node_ptr list)
{
    /* Note that we don't really need to have the variable "current" here,
       as we could just advance list itself if we preferred. (Some of the other
       list functions also make use of an additional such variable.) */
    node_ptr current = list;

    while(current)
    {
        node_ptr to_free = current;
        current = current->next;
        free(to_free);
        /* Note that the simpler: 
           free(current); 
           current = current->next;
           makes the mistake of using dynamically allocated memory after
           it's been freed */
    }
}

/* Function to insert n at front of list */
void insert_at_front(int n, node_ptr list)
{
    node_ptr new_node = (node_ptr) malloc(sizeof(struct node));
    new_node->data_item = n;
    new_node->next = list->next;
    list->next = new_node;
}

/* Function to print list */
void print(node_ptr list)
{
    node_ptr current = list->next;

    while(current)
    {
        printf("%d ", current->data_item);
        current = current->next;
    }
    printf("\n");
}

/* Function to insert n in (non-decreasing) order in list - assuming list 
   items are already in (non-decreasing) order. */
void insert_in_order(int n, node_ptr list)
{
    node_ptr before = list;
    node_ptr new_node = (node_ptr) malloc(sizeof(struct node));
    new_node->data_item = n;

    /* Move along list until right place is found, looking for node after
       which new node should go */
    while(before->next && (before->next->data_item < n))
    {
        before = before->next;
    }

    new_node->next = before->next;
    before->next = new_node;
}

