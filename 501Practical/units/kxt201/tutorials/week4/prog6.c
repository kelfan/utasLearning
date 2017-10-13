/* prog6.c - Mike Cameron-Jones 22/1/04, updated 16/2/07

This is an example program for which you should first work out a (simple and
tight) O() expression for the running time, then time, change it to double
the value of n (i.e. change to n = 50) and time again, to see whether the
change in running time is close to what would be expected from your O()
expression.

(Note that the real inner loop does not depend on n, and is just there to make
the times larger, otherwise the time with n = 25 will be smaller than
desirable. The time with n = 50 will be much longer than any of the other times
to be measured in this week's work, so is not likely to be worth measuring
repeatedly to get a more accurate result.)

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog6.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int main()
{
    int i, j, k, l, pseudo_inner_count = 0, n = 25;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i*i; j++)
        {
            for(k = 0; k < i*j; k++)
            {
                pseudo_inner_count++;
                for(l = 0; l < 10; l++);
            }
        }
    }

    printf("Body of \"inner\" loop entered %d times\n", pseudo_inner_count);

    return 0;
}
