/* prog10.c - Mike Cameron-Jones 22/1/04, updated 16/2/07

This is an example program for which you should first work out a (simple and
tight) O() expression for the running time, then time, change it to double 
the value of n (i.e. change to n = 200) and time again, to see whether the
change in running time is close to what would be expected from your O()
expression.

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog10.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int square(int m);

int main()
{
    int i, wrong_count = 0, n = 100;

    for(i = 0; i < square(n); i++)
    {
        wrong_count++;
    }

    printf("%d %d\n", wrong_count, square(wrong_count));

    return 0;
}

int square(int m)
{
    int i, j = 0;

    for(i = 0; i < m * m; i++)
    {
        j++;
    }

    return j;
}
