/*  prog1.c - Mike Cameron-Jones - 3/03/03, comment altered 23/12/03
    (based upon own C program from past first year unit)
    
    This program makes use of linked list code implemented in list.c, with
    the appropriate types and prototypes defined in list.h, which is included
    in this program. You should look at the definitions in list.h and 
    the code in list.c as well as at this program.

    The program accepts a series of integers from the terminal, entering each 
    at the front of the list, then prints the list out from the front. (This
    gives a stack-like effect as the first thing printed out is the last
    added.)
    
    Try it as it is. You can compile (and link) the relevant source files with:
    gcc -Wall -ansi -pedantic -O prog1.c list.c
    
    (If prog1.c and list.c are the only .c files in the current directory, you
    can compile and link with:
    gcc -Wall -ansi -pedantic -O *.c
    as the *.c will match prog1.c and list.c. It is likely that this is the
    command with which your assignments will be required to compile and link.)

    Then alter the program to use insert_in_order instead of insert_at_front, 
    so that numbers are stored in order, and will be printed out in order.

    Now try writing some functions for yourself. In each case, the prototype
    should go in the header file (list.h), the code for the function in the
    implementation file (list.c), and the call to make use of it in the
    main in this file.

    First try writing and testing a function to find the number of items in a
    list, with function prototype: int length(node_ptr list);
    (For example if the list contains 2, 3, 5, 7, 11, 13 and 17, the function
    should return 7, as there are 7 items in the list.)

    Then try writing and testing a function to sum the integer values in a 
    list, with function prototype: int sum_list(node_ptr list);
    (For example if the list contains 2, 3, 5, 7, 11, 13 and 17, the function
    should return 58.)

    Then try writing and testing a function to find the (first) node 
    containing a specific number, returning a pointer to the node if the
    number is present in the list, or NULL if the number is not present, 
    with function prototype:  node_ptr find(int n, node_ptr list);
    (You might find Weiss's code a useful starting point.)

    Finally, try writing and testing a function to delete (the first
    occurrence of) a number from the list, appropriately freeing the relevant
    node, with function prototype: void delete(int n, node_ptr list);
    The function should leave the list unaltered if the number does not
    occur in the list. (Again Weiss's code might be a useful starting point,
    and also aspects of insert_in_order are relevant.)

*/

#include <stdio.h>
#include "list.h"

int main()
{
    int n;
    node_ptr the_list = create();

    printf("Enter a series of positive integers terminated by zero\n");
    printf("For example: 8 6 4 3 5 7 0\n");

    while(1) /* loop until loop broken out of */
    {
        scanf("%d", &n);
        if(!n) break; /* break out of loop when n is 0 */

        insert_at_front(n, the_list);
    }

    print(the_list);

    destroy(the_list); /* give back dynamically allocated memory in the list */

    return 0;
}
