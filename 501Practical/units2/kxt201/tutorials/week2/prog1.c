/* prog1.c - Mike Cameron-Jones - 16/2/02, altered 31/1/03

This is a simple program for familiarisation with the process of
compiling and running a C program on the Unix system.

The following command will compile it:
    gcc prog1.c

The executable is called "a.out", and can be executed as a command
at the prompt, try it, (without the quotes!). (If you can't execute it, 
try "./a.out" - you may have things set so that the system doesn't look
in your current directory for executables.)

Now try using Unix's facilities to redirect the input. First create
a file, for example "wombat" that contains two floating point numbers each
followed by a carriage return, (just like the input that you've typed in
before). Then run the program with the input coming from the file:
    a.out < wombat
You should get the same output as if you'd typed that input at the terminal.

Now try redirecting the output as well, for example to "aardvark":
    a.out < wombat > aardvark
Take a look at "aardvark", and you should see what was previously
printed on the terminal. 

Now try putting a mistake into the program, by change %f to %d in the printf,
compiling and executing - note that the mistake is not noticed by the system.
This sort of mistake could be picked up by using some compiler options.
From now onwards in this unit, you should always use the options -Wall
(to get warnings about apparent mistakes) and -ansi -pedantic (so that you
are warned about non-standard code that gcc might otherwise allow), 
and usually use -O (which is really about optimising the produced code, but 
also generates some additional warnings about apparent mistakes) e.g.:
    gcc -Wall -ansi -pedantic -O prog1.c
Try this, and note that the compiler gives a warning about the the nature of
the apparent mistake and its location, including the line number in the file.
(It is likely that assignments will be required to compile without errors
or warnings using these compiler options.)

*/

#include <stdio.h>

float sum(float a, float b); /* the function prototype for sum */

int main()
{
    float x, y;

    printf("Enter a value for x, e.g. 1.3\n");
    scanf("%f", &x);
    printf("Enter a value for y, e.g. 2.4\n");
    scanf("%f", &y);

    printf("The value of x + y is %f\n", sum(x,y));

    return 0;
}

float sum(float a, float b)
{
    return a + b;
}
