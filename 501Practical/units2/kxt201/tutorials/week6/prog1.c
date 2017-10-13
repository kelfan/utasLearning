/* prog1.c - Mike Cameron-Jones - 4/03/03
   (based upon past programs from earlier units)

   This program makes use of a binary search tree (BST) implementation in
   bst.c, with the appropriate types and prototypes defined in bst.h, which is
   included in this program. You should look at bst.h and bst.c as well as
   at this program.

   The program accepts a series of integers placing them in a BST, then
   prints it out in order, then accepts a series of integers, deleting them
   from the BST (if previously present), then prints the BST out in order.

   Try it as it is. You can compile (and link) the relevant source files with:
   gcc -Wall -ansi -pedantic -O prog1.c bst.c

   Then try writing some functions for yourself. In each case, the prototype
   should go in the header file (bst.h), the code for the function in the
   implementation file (bst.c), and the call to make use of it in the main
   in this file.

   First try writing functions to print out the BST in preorder and postorder,
   with function prototypes: void print_pre_order(node_ptr tree) and 
   void print_post_order(node_ptr tree) respectively. (The code for each is 
   only slightly different to the code for print_in_order.)

   Then try writing a function to return the height of a tree, with
   prototype: int height(node_ptr tree). (You might find Weiss's code a
   useful starting point.)

   Then try writing a function to return a count of the number of items
   in a BST, with prototype: int count(node_ptr tree). (You might find the 
   previous function a useful starting point for this.)
*/

#include <stdio.h>
#include "bst.h"

int main()
{
    int n;
    node_ptr the_tree = create();

    printf("You can now put some integers into a BST\n");
    printf("Enter a series of positive integers terminated by zero\n");
    printf("For example: 8 6 4 3 5 7 0\n");
    while(1) /* loop until loop broken out of */
    {
        scanf("%d", &n);
        if(!n) break; /* break out of loop when n is 0 */

        the_tree = insert(n, the_tree); /* note how insert is used */
    }
    printf("The BST now contains: ");
    print_in_order(the_tree);
    printf("\n");

    printf("\nYou can now delete some integers from the BST\n");
    printf("Enter a series of positive integers terminated by zero\n");
    printf("For example: 8 6 4 3 5 7 0\n");
    while(1) /* loop until loop broken out of */
    {
        scanf("%d", &n);
        if(!n) break; /* break out of loop when n is 0 */

        if(!find(n, the_tree)) /* just checking for NULL result */
        {
            printf("%d is not present in the tree\n", n);
        }
        else
        {
            the_tree = delete(n, the_tree); /* note how delete is used */
        }
    }
    printf("The BST now contains: ");
    print_in_order(the_tree);
    printf("\n");

    destroy(the_tree); /* give back dynamically allocated memory in the tree */

    return 0;
}
