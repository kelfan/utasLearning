/* prog3.c - Mike Cameron-Jones 22/1/04, updated 16/2/07

This is an example program for which you should first work out a (simple and
tight) O() expression for the running time, then time, change it to double the
value of n (i.e. change to n = 40000) and time again, to see whether the
change in running time is close to what would be expected from your O()
expression.

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog3.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int main()
{
    int i, j, inner_count = 0, n = 20000;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            inner_count++;
        }
    }

    printf("Innermost statement executed %d times\n", inner_count);

    return 0;
}
