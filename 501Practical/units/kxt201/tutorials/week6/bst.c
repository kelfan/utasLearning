/* bst.c - Mike Cameron-Jones 11/03/03, with a comment updated 20/03/06
   (based upon past programs from earlier units)

   This code illustrates the use of pointers to implement a BST of ints.
   (Implementation does not add duplicate items, and does nothing when
   attempt is made to delete item not present.)
*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* Function to create an empty tree */
node_ptr create(void)
{
    return NULL; /* questionable whether it's worth having such a function */
}

/* Function to return dynamically allocated memory in tree */
void destroy(node_ptr tree)
{
    /* If not empty, destroy sub-trees then free this node */
    if(tree)
    {
        destroy(tree->left); 
        destroy(tree->right);
        free(tree);
    }
    return;
}

/* Function to insert n into BST, returning tree with n inserted.
   (Leaves BST unaltered if n is already present.)
   Note: to be used in style: t = insert(n, t); where t is a BST. 
*/
node_ptr insert(int n, node_ptr tree)
{
    if(!tree) /* found where to put it, create and initialise node */
    {
        tree = (node_ptr) malloc(sizeof(struct node));
        tree->data_item = n;
        tree->left = tree->right = NULL;
    }
    /* otherwise put in left / right sub-tree as appropriate */
    else if(n < tree->data_item)
    {
        tree->left = insert(n, tree->left);
    }
    else if(n > tree->data_item)
    {
        tree->right = insert(n, tree->right);
    }
    /* if n == tree->data_item, just leave tree as is */

    return tree;
}

/* Function to print tree in order */
void print_in_order(node_ptr tree)
{
    /* If not empty, print left subtree, item at node, then right subtree */
    if(tree)
    {
        print_in_order(tree->left);
        printf("%d ", tree->data_item);
        print_in_order(tree->right);
    }
    return;
}

/* Function to find node containing n in BST, returning NULL if n not present*/
node_ptr find(int n, node_ptr tree)
{
    if(!tree || (n == tree->data_item)) /* not present, or present here */
    {
        return tree;
    }
    /* otherwise look in left / right subtree as appropriate */
    else if(n < tree->data_item)
    {
        return find(n, tree->left);
    }
    else
    {
        return find(n, tree->right);
    }
}

/* Function to help handle the awkward case in deletion, where the item to be
   deleted is at a node with two children, and hence want to replace the
   item with its inorder successor and delete the node that contains that
   inorder successor. This function is static so that it is only visible
   in this file, as it's not intended that ordinary users of the BST code
   call it directly. It should be used on the right subtree of the node
   containing the item to be deleted, e.g.:
   t->right = leftmost_delete_replace(&(t->data_item), t->right); where t is 
   the node containing the item to be deleted.
*/
static node_ptr leftmost_delete_replace(int *ptrto_to_be_replaced, 
                                        node_ptr tree)
{
    /* If leftmost, have found inorder successor, copy value from here to
       node containing item to be deleted, then cut out and free this node */
    if(tree->left == NULL)
    {
        node_ptr to_free = tree;
        *ptrto_to_be_replaced = tree->data_item;
        tree = tree->right;        
        free(to_free);
    }
    else
    {
        tree->left = leftmost_delete_replace(ptrto_to_be_replaced, tree->left);
    }
    return tree;
}

/* Function to delete n from BST, returning tree with n deleted. 
   (Leaves BST unaltered if n not present.)
   Note: to be used in style: t = delete(n, t); where t is a BST.
*/
node_ptr delete(int n, node_ptr tree)
{
    if(tree)
    {
        if(n == tree->data_item) /* found item to delete */
        {
            /* two child case is awkward, handle with helper function */
            if(tree->left && tree->right)
            {
                tree->right = 
                    leftmost_delete_replace(&(tree->data_item), tree->right);
            }
            else /* one / zero child case is easier, cut out and free */
            {
                node_ptr to_free = tree;
                if(tree->left)
                {
                    tree = tree->left;
                }
                else
                {
                    tree = tree->right;
                }
                free(to_free);
            }
        }
        /* otherwise delete from left / right subtree as appropriate */
        else if(n < tree->data_item)
        {
            tree->left = delete(n, tree->left);
        }
        else 
        {
            tree->right = delete(n, tree->right);
        }
    }
    return tree;
}
