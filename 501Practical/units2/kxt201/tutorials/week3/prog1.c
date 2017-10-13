/* prog1.c - Mike Cameron-Jones - 16/02/02, altered 10/02/03

Example of using some string functions

Try the program as it is.

The program relies upon the user not to overflow the char arrays.
Try entering a 20 character second name and see what happens. 
*/

#include <stdio.h>
#include <string.h> /* For the string function prototypes */

int main()
{
    char first_string[11] = "Hi";
    char second_string[11] = { 'H', 'i', '\0' };
    char third_string[11];

    printf("%s or is that %s?\n", first_string, second_string);

    printf("Enter two different names, each at most 10 characters long\n");
    printf("For example: john mary\n");
    scanf("%s %s", first_string, second_string); /* lack of & to be explained*/

    /* The following comparison makes use of strcmp, for which the return
       value is:
       negative, 0, positive 
       for first argument 
       before, equal to, after
       second argument respectively */
    if(strcmp(first_string, second_string) < 0)
    {
        printf("%s is before %s\n", first_string, second_string);
    }
    else
    {
        printf("%s is after %s\n", first_string, second_string);
    }

    strcpy(third_string, first_string); /* copy to first argument from second*/

    /* The following is equivalent to
       if(strcmp(first_string, third_string) == 0)
       In a test in C, 0 (including NULL) is treated as false and a value that
       is not 0 as true. (There isn't a genuine boolean type.) If you prefer
       the explicit comparison to 0, just use it */
    if(!strcmp(first_string, third_string))
    {
        printf("but %s equals %s\n", first_string, third_string);
    }

    return 0;
}
