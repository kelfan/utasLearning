/* prog3.c - Mike Cameron-Jones 16/02/02, altered 10/02/03

Example of linking structs that contain pointers to structs

Try it as it is.

Then modify the program to use a fourth node, linking this in after node3
Try your new version.
*/

#include <stdio.h>

struct node
{
    int data_item; /* struct stores an int */
    struct node *next; /* and a pointer to another struct */
};

int main()
{
    struct node node1, node2, node3, *current;

    /* Put something into the nodes */
    printf("Enter three integers\n");
    scanf("%d %d %d", &node1.data_item, &node2.data_item, &node3.data_item);

    /* Link the nodes up */
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL; /* Mark node 3 as the end node */

    /* Now can print all the data items by going through node 1 */
    printf("\n%d\n", node1.data_item);
    printf("%d\n", node1.next->data_item); /* node2's data item */
    printf("%d\n\n", node1.next->next->data_item); /* node3's data item */

    /* Usually don't know how many items are linked and loop to end node */
    current = &node1; /* Start at front */
    while(current) /* Use the equivalent while(current != NULL) if you prefer*/
    {
        printf("%d\n", current->data_item); /* print out current data item */
        current = current->next; /* move on to next node */
    }

    return 0;
}
