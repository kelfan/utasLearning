/*  bst.h - Mike Cameron-Jones - 4/03/03
   (based upon past programs from earlier units)
    
    This is just the header file for the functions implemented in bst.c

    Unlike Weiss's BST header file, this one includes the definition of the 
    node struct type. Weiss's approach might be better in terms of
    encapsulation.
*/

#ifndef _BST_H
#define _BST_H

/* Define node and node_ptr type - note that the names clash with those
   for the list types. The use of longer names like list_node and tree_node 
   would have the advantage of avoiding this clash.
*/
typedef struct node *node_ptr;
struct node
{
    int data_item;
    node_ptr left;
    node_ptr right;
};

/* Function to create an empty tree */
node_ptr create(void);

/* Function to return dynamically allocated memory in tree */
void destroy(node_ptr tree);

/* Function to insert n into BST, returning tree with n inserted.
   (Leaves BST unaltered if n is already present.)
   Note: to be used in style: t = insert(n, t); where t is a BST. 
*/
node_ptr insert(int n, node_ptr tree);

/* Function to print tree in order */
void print_in_order(node_ptr tree);

/* Function to find node containing n in BST, returning NULL if n not present*/
node_ptr find(int n, node_ptr tree);

/* Function to delete n from BST, returning tree with n deleted. 
   (Leaves BST unaltered if n not present.) 
   Note: to be used in style: t = delete(n, t); where t is a BST.
*/
node_ptr delete(int n, node_ptr tree);

#endif
