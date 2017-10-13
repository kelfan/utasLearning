
/********************************************************************************/
/*	The 1st implementation of the Dining Philosophers Problem - part 1	*/
/********************************************************************************/

/*	To compile: gcc -o start start.c		*/
/*	Need philo.c to run this program		*/
/*	To compile philo.c: gcc -o philo philo.c	*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SLEEP "7"

/* This program will fork() 5 new processes.
   Each forked process then execs program philo, which
   is the output file of philo.c

   philo.c program simulates a dinining philosopher who 
   sleeps for SLEEP many seconds before eating for some
   time using the left and right chopsticks assigned to it
*/ 

main() {	
	int why;
	pid_t p1, p2, p3, p4, p5;
	/* Lay the chopsticks */
	unlink("chopstick1"); unlink("chopstick2");
	unlink("chopstick3"); unlink("chopstick4"); unlink("chopstick5");
	/* Forks 5 philosophers */
	if (p1=fork()==0) {
		/* Philo 1 */
		execl("./philo","philo","chopstick1","1","chopstick2",
			"1: ", SLEEP,0);
		perror("Philo 1:");
	} else if (p2=fork()==0) {
		/* Philo 2 */
		sleep(5);
		execl("./philo","philo","chopstick2","2","chopstick3",
			"     2: ",SLEEP,0);
		perror("Philo 2:");	
	} else if (p3=fork()==0) {
		/* Philo 3 */
		sleep(5);
		execl("./philo","philo","chopstick3","3","chopstick4",
			"          3: ",SLEEP,0);	
		perror("Philo 3:");	
	} else if (p4=fork()==0) {
		/* Philo 4 */
		sleep(5);
		execl("./philo","philo","chopstick4", "4", "chopstick5",
			"               4: ",SLEEP,0);
		perror("Philo 4:");
	} else if (p5=fork()==0) {
		/* Philo 5 */
		execl("./philo","philo","chopstick5","5","chopstick1",
			"                    5: ",SLEEP,0);
		perror("Philo 5:");
	} else {
		wait(&why);
		wait(&why);
		wait(&why);
		wait(&why);
		wait(&why);

		printf("Done\n");
	}

}
