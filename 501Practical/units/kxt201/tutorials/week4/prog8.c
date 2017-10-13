/* prog8.c - Mike Cameron-Jones 22/1/04, updated 16/2/07

This is an example program for which you should first work out a (simple and
tight) O() expression for the running time, then time, change it to double
the value of n (i.e. change to n = 16) and time again, to see whether the
change in running time is close to what would be expected from your O()
expression.

(Note that the real inner loop does not depend on n, and is just there to make
the times large enough to measure.)

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog8.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int main()
{
    int i, j, k, pseudo_inner_count = 0, n = 8;

    for(i = n; i > 1; i /= 2)
    {
        for(j = 0; j < n; j++)
        {
            pseudo_inner_count++;
            for(k = 0; k < 50000000; k++);
        }
    }

    printf("Body of \"inner\" loop entered %d times\n", pseudo_inner_count);

    return 0;
}
