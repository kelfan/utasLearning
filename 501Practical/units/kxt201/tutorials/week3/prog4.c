/* prog4.c - Mike Cameron-Jones 4/02/03

Example of reading words into a fixed size buffer then storing them
in dynamically allocated memory.

Try it as it is.

Although each word is stored in dynamically allocated memory, the array in
which the pointers are stored is itself of fixed size. Modify the program to
ask the user how many words they want to enter, and read this into n,
then create a dynamically allocated array of the appropriate size to hold that
many pointers. To do this, as well as reading n, change the definition of a to:
char **a;
(a is now a pointer to pointer to char)
and get the memory as follows (assuming n is the number of words):
a = (char **) malloc(n * sizeof(char *));
before reading the words.
This dynamically allocated memory should also be freed when no longer needed
(after all the a[i]'s have been freed).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 10;
    char *a[10];
    char buffer[101];
    int i;

    printf("Enter %d words, each containing no more than 100 characters\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", buffer);
        a[i] = (char *) malloc(strlen(buffer) + 1);
        /* We should always consider checking that result of malloc isn't NULL,
           as it returns NULL when out of memory to allocate dynamically, but 
           we'll not bother to check in this unit. (You'll see that Weiss 
           does.)
        */
        strcpy(a[i], buffer);
    }

    printf("\nYou entered:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }

    /* Free the dynamically allocated memory now that it is no longer needed
       - not strictly necessary as the system will recover the memory anyway
       on termination, but not bothering can be a source of future memory
       leaks if the code gets recycled as part of something larger, so it's
       best to think about when to free while you're thinking about the 
       code that gets the dynamically allocated memory.
    */
    for(i = 0; i < n; i++)
    {
        free(a[i]);
    }

    return 0;
}
