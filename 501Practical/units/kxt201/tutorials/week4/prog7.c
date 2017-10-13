/* prog7.c - Mike Cameron-Jones 22/1/04, updated 16/2/07

This is an example program for which you should first work out a (simple
and tight) O() expression for the running time, then time, change the value
of n to what you think will (roughly) double the time and time again, to see 
whether the change in running time is close to what you intended.

(Note that the real inner loop does not depend on n, and is just there to make
the times large enough to measure.)

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog7.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int main()
{
    int i, j, pseudo_inner_count = 0, n = 32768;

    for(i = n; i > 1; i /= 2)
    {
        pseudo_inner_count++;
        for(j = 0; j < 50000000; j++);
    }

    printf("Body of \"inner\" loop entered %d times\n", pseudo_inner_count);

    return 0;
}
