/* prog9.c - Mike Cameron-Jones 04/02/04, updated 16/2/07

This is an example program for which you should first work out a (simple
and tight) O() expression for the running time, then repeatedly change
it to double the value of n (i.e. n = 65536, then n = 131072, etc) and 
time again, until the time is over two seconds, and notice how the time 
changes as you keep changing n.

Note:
The program should be compiled as:
gcc -Wall -ansi -pedantic prog9.c
Although in this unit the -O option should normally be used, the (longer)
running time given by not using the -O option is the time wanted here.
(Longer running times tend to be measured more accurately -- in terms of
percentage variation.)

*/

#include <stdio.h>

int main()
{
    int i, j, count = 0, n = 32768;

    for(i = n; i > 1; i /= 2)
    {
        for(j = 0; j < 5000000; j++)
        {
            count++;
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 2000; j++)
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
