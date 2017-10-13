/* prog2.c - Mike Cameron-Jones - 16/02/02, altered 31/01/03

Simple struct example

Try it as it is.
Then put in some of the remaining months by name and try some of them.
*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

void print_date(struct date whenever); /* note awkwardness of "struct date" */

int main()
{
    struct date birth, twenty_first;

    printf("Enter your date of birth in numbers for example: 15 2 2002\n");
    scanf("%d %d %d", &birth.day, &birth.month, &birth.year);

    twenty_first = birth; /* Note that this is copying all the members */
    twenty_first.year += 21;
    printf("You were born on ");
    print_date(birth);
    printf("and your twenty first birthday is / was on ");
    print_date(twenty_first);

    return 0;
}

void print_date(struct date whenever)
{
    printf("%d ", whenever.day);

    switch(whenever.month)
    {
        case 1:  printf("January");
                 break;
        case 2:  printf("February");
                 break;
        case 3:  printf("March");
                 break;
        default: printf("%d", whenever.month);
                 break;
    }

    printf(" %d\n", whenever.year);

    return;
}
