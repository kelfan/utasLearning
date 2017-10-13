// -------------------------------------------------------------------------
//
//	The Dining Philosophers Problem - 2nd implementation
//
//
// -------------------------------------------------------------------------
//
//	To compile: g++ -Wno-deprecated -o philo2 philo2.cc
//

#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


// constants
const short NumOfPhilosophers=5;     	// the number of philosophers 
const short TimeSpentEating=2; 		// how long to eat for (seconds)
const short TimeSpentThinking=2;	// how long to think for (seconds)


#define   Left(p)          (p)		// chopstick macros
#define   Right(p)         (((p) + 1) % NumOfPhilosophers)


typedef   int*    semaphore;
semaphore      chopstick[NumOfPhilosophers];	 /* global array */ 


// Function prototypes
semaphore      make_semaphore(void);
void           philosopher(int me); 
void           pick_up(int me);
int            pipe(int pd[2]);
void           put_down(int me);   
void           signal(semaphore s); 
void           waiting(semaphore s);


main()
{
	short	i;

	// create 5 chopsticks (semaphores) and signal that they're all free
	for (i = 0; i < NumOfPhilosophers; i++)
	{
		chopstick[i] = make_semaphore(); 
		signal(chopstick[i]);
	}


	// create 4 additional philosopher processes
	for (i = 0; i < NumOfPhilosophers - 1; i++)
		if (fork() == 0)	// fork a child process
			break;

	// every child created above as well as the parent all drop through
	// to here, so we end up with 5 copies of philosopher running
	// the value in the variable i will be the philosopher number
	philosopher(i);		// go be a philosopher
}


// ---------------------------------------------------------------------------------
// be a philosopher
// 
// this function runs as an endless loop
// ---------------------------------------------------------------------------------

void philosopher(int me)
{
	char   *s;  
	int    turns = 1;

	while (1)
	{
		// get some chopsticks
		pick_up(me);


		// set the string variable s to
		// the sequence "st", "nd", "rd", or "th", depending on the
		// value of turns, so that we can print things like "1st", "2nd", etc.
		
		if ( turns == 1)
			s = (char *)"st";
		else if (turns == 2)
			s = (char *)"nd";
		else if (turns == 3)
			s = (char *)"rd";
		else s = (char *)"th";

		// s = turns == 1 ? "st" : turns == 2 ? "nd" : turns == 3 ? "rd" : "th";


		// now eat for a while
		if ( me == 0 )
		   cout << "Philosopher " << me << " eating for the " << turns << s << " time\n";
		else if ( me == 1 )
		   cout << "	Philosopher " << me << " eating for the " << turns
<< s << " time\n";
		else if ( me == 2 )
		   cout << "		Philosopher " << me << " eating for the " << turns
<< s << " time\n";
		   else if ( me == 3 )
		cout << "			Philosopher " << me << " eating for the " << turns
<< s << " time\n";
		else
		   cout << "				Philosopher " << me << " eating for the " << turns
<< s << " time\n";
		sleep(TimeSpentEating);
		turns++;


		// done eating, so put the chopsticks down
		put_down(me);


		// now think for a while
		if (me==0)
		   cout << "Philosopher " << me << " thinking\n";
		else if (me==1)
		   cout << "	Philosopher " << me << " thinking\n";
		else if (me==2)
		   cout << "		Philosopher " << me << " thinking\n";
		else if (me==3)
		   cout << "			Philosopher " << me << " thinking\n";
		else
		   cout << "				Philosopher " << me << " thinking\n";

		sleep(TimeSpentThinking);
	}
}



// ---------------------------------------------------------------------------------
// pick up the chopsticks
// ---------------------------------------------------------------------------------

void pick_up(int me)
{
	// get the first chopstick
	waiting(chopstick[Left(me)]);

	if (me==0)
	   cout << "Philosopher " << me << " picks up left chopstick\n";
	else if (me==1)
	   cout << "	Philosopher " << me << " picks up left chopstick\n";
	else if (me==2)
	   cout << "		Philosopher " << me << " picks up left chopstick\n";
	else if (me==3)
	   cout << "			Philosopher " << me << " picks up left chopstick\n";
	else
	   cout << "				Philosopher " << me << " picks up left chopstick\n";

	// simulate slow picking up to encourage deadlock
	sleep(1);

	// now get the other chopstick
	waiting(chopstick[Right(me)]);

	if (me==0)
	   cout << "Philosopher " << me << " picks up right chopstick\n";
	else if (me==1)
	   cout << "	Philosopher " << me << " picks up right chopstick\n";
	else if (me==2)
	   cout << "		Philosopher " << me << " picks up right chopstick\n";
	else if (me==3)
	   cout << "			Philosopher " << me << " picks up right chopstick\n";
	else
	   cout << "				Philosopher " << me << " picks up right chopstick\n";

}



// ---------------------------------------------------------------------------------
// put down both chopsticks
// ---------------------------------------------------------------------------------

void put_down(int me)
{
	signal(chopstick[Left(me)]);
	signal(chopstick[Right(me)]);
}



// ---------------------------------------------------------------------------------
// create a semaphore
// ---------------------------------------------------------------------------------
//
// in this code we implement a semaphore using the unix pipe facility
// to create a semaphore, we create a pipe
// five semaphores get created in main(), one for each chopstick

semaphore make_semaphore(void)
{
	int *sema;

	// allocate enough space for the 2 pipe file descriptors
	sema = (int *) calloc(2, sizeof(int));

	// create the pipe
	pipe(sema);

	// return a pointer to the file descriptors
	return sema;
}



// ---------------------------------------------------------------------------------
// wait on a semaphore
// ---------------------------------------------------------------------------------
//
// since we've implemented semaphores as pipes, waiting on a semaphore
// is the same as reading the token from the pipe 
//
// if there is no token waiting in the pipe, the read() call will
// block this process until some data is available

void waiting(semaphore s)
{
	int junk;

	if (read (s[0], &junk, 1) <= 0)
	{
		cout << "ERROR: waiting() failed, check semaphore creation. \n";
		exit(1);
	}
}


// ---------------------------------------------------------------------------------
// signal a semaphore
// ---------------------------------------------------------------------------------
//
// signaling a semaphore is implemented by writing a token to the pipe.
// the token in this case is a single character "x"

void signal(semaphore s)
{
	if (write(s[1], "x", 1) <=0)
	{
		cout << "ERROR: write() failed, check semaphore creation. \n";
		exit(1);
	}
}


// The end of the program
