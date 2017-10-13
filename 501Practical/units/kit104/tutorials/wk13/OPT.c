/*
	The filter OPT takes a command line argument indicating the
	number of page frames in the main memory of the simulated memory
	in a virtual memory environment using the Optimal 
	algorithm to free page frames.
	
	The standard input is a stream of lines containing two items.
	Each line is: (1) Action and (2) page number. 
	
	An action can be R (=read to page); W (=write into page); or
	F (=Finish). Second argument is the page number on which the 
	action happenes.
	
	The program simulates a virtual memory system. It prints the 
	result indicating the number of read and write actions in 
	the stdin stream. It also tells us the number of page faults
	that resulted in page ins to occur. Number of page faults 
	leading to disk writes of dirty pages are also generated.
*/
	
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PAGES 1000
#define ACCESSES 100000

int frame[PAGES], dirty[PAGES], accesses[ACCESSES];  
long	frames, now, allAccess;
char act[ACCESSES];


void setup() {
	int i;
	
	for (i=0;i<frames;i++) {
		frame[i]=-1;
		dirty[i]=0;
	}
	ungetc(' ',stdin);
}

void readNcompactAccesses() {
	int reads=0, writes=0;
	long g;
	
	allAccess=0;
	scanf(" %c %i", act+allAccess,accesses+allAccess);
	if (act[allAccess]=='R')
		reads++;
	else if (act[allAccess]=='W')
		writes++;
	
	while (allAccess<ACCESSES && act[allAccess]!='F') {		
		allAccess++;
		
		scanf(" %c %i", act+allAccess, accesses+allAccess);
		if (act[allAccess]=='R')
			reads++;
		else if (act[allAccess]=='W')
			writes++;
			
		if (accesses[allAccess]==accesses[allAccess-1] && 
			act[allAccess]==act[allAccess-1])
				allAccess--;
		else if (accesses[allAccess]==accesses[allAccess-1] &&
			act[allAccess]=='R') // One before was a Write
				allAccess--;
	}
	
	printf("Stats\nRead accesses %i\nWrite accesses %i\n",reads,writes);
//	printf("Compacted reads/writes %i\n",allAccess);
//	for (g=0;g<allAccess;g++)
//	printf("%c %i\n",act[g],accesses[g]);
}	

int opt() { // Locates optimal page frame for replacement
	long i, last, useless[PAGES], where; 
	
	for (i=0;i<frames;i++) 
		if (frame[i]==-1) return i;	// If there is as yet unused frame
	
	for (i=0;i<frames;i++) useless[i]=i;
	last=frames-1;
	
	where=now+1; // Look into future accesses
/* Frames listed in array useless from index 0 to last have not found use in
   any access from now to where. We will increment where till only one frame
   remains that has not been used. This one is obviously the one to find last use.
*/
	while (last>0 && where<allAccess) {
		for (i=0;i<last;i++) 
			if (frame[useless[i]]==accesses[where]) {
				useless[i]=useless[last];
				last--;
			} 	
		where++;
	}
	 
			return useless[0];
}
	


int main(int argc, char *argv[]) {
	int diskReads=0, diskWrites=0;
	int ll, i, pg;
	char rw;

	if (argc!=2) {
		fprintf(stderr,"Usage: OPT FrameCount\n");
		fprintf(stderr,"Frame count not to be over 1000\n");
		exit(0);
	}
	
	frames = atoi(argv[1]);
	setup();
	readNcompactAccesses();

	
	for (now=0;now<=allAccess;now++) { // Process page

		rw=act[now];
		pg=accesses[now];
		if (rw=='R') {
			for (i=0;i<frames;i++)
				if (frame[i]==pg) {
					i=frames+10; // Page is in a frame
				}
			if (i==frames)  {
				diskReads++;
				ll=opt();  // Where read
				//fprintf(stderr,"%i\n",ll);
			
				if (dirty[ll]==1) 
					diskWrites++;
				
				dirty[ll]=0; 
				frame[ll]=pg;
			}
		}
		else if (rw=='W') {
			for (i=0;i<frames;i++)
				if (frame[i]==pg) {
					dirty[i]=1;
					i=frames+10;
				}
			if (i==frames) {//page did not exist
				diskReads++;
				ll=opt();  // Where read
			
				if (dirty[ll]==1) 
					diskWrites++;
				
				dirty[ll]=1;
				frame[ll]=pg;
			}
		}
		else {break;}
	}
	
	printf("Reads from the disk %i\nWrites to disk %i\n", 
		diskReads,diskWrites);
}
			
				
				
		
