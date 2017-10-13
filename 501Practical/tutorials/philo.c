
/********************************************************************************/
/*	The 1st implementation of the Dining Philosophers Problem - part 2	*/
/********************************************************************************/

/*	To compile: gcc -o philo philo.c			*/
/*	Do not run this program independently			*/
/*	Must run start, which is the output file of start.c	*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>

main(int argc, char* argv[]) {
	/* Command line arguments are as follows:
	index	argv[] member's specification
	0   	Name of the program
	1   	Left chopstick
	2	Philosopher's Id number
	3   	Right chopstick
	4	Distinguishing name for printout
	5	Sleep time
	*/
	
	int left, right, age, waited, j;
	
	
	/* Life cycle of a philosopher */
	
	for (age=1;age<100;age++) {
		/* A simulated philosopher thinks in sleep and wastes CPU time */
		printf("%sMy age is %i. I am busy thinking.\n",argv[4],age);
		sleep((7+age*atoi(argv[5]))%13);
		printf("%sI am hungry; very hungry.\n",argv[4]);
		waited=0;

		/* Get the left chopstick. Only one person can own a chopstick at a time.*/
		
		printf("%sLooking for my left chopstick.\n",argv[4]);
		while (left=open(argv[1],O_CREAT|O_EXCL)<0) {
			sleep(1); 
			if (waited>80) 
			{printf("%s Died without a chopstick - waited too long.\n", argv[4]);
			 exit(0); 
			} else waited++;
		}
		printf("%sI now have my left chopstick.\n",argv[4]);
		
		if (waited>80) 
			{printf("%s Died with a chopstick - waited too long.\n", argv[4]);
			 exit(0); 
		} else waited++;
		
		/* Trying to get the right chopstick */
		printf("%sLooking for my right chopstick.\n",argv[4]);
		while (right=open(argv[3],O_CREAT|O_EXCL)<0) { 
			sleep(1);
			if (waited>80) {
			printf("%sDied with a chopstick - waited too long.\n",argv[4]);
			exit(0); 
			} else waited++;
		}
		printf("%sI now have my right chopstick.\n",argv[4]);
		
		/* Enjoy the food */
		
		printf("%sI am going to eat now. I waited %i weeks.\n", 
			argv[4],waited);
		sleep((13*age+7*atoi(argv[2]))%17);
		printf("%sFood was good.\n",argv[4]);
		
		/* Return forks */
		
		printf("%sReturned my left chopstick.\n",argv[4]);
		close(left); unlink(argv[3]);
		printf("%sReturned my right chopstick.\n",argv[4]);
		close(right); unlink(argv[1]);
	
	}

	printf("%sRetires\n");
}
