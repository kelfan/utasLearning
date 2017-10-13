/*
	The program is a filter to convert memory addresses into 
	page number references. Page size is given as the command
	line argument.
*/

#include <stdio.h>
#include <stdlib.h>

/* Read and write requests made by the sort programs to
   addresses while accessing the arrays are virtual addresses.
   
   The program converts those lists into arrays of page accesses.
   
   USAGE: pageReferences pagesize
   pagesize should be 256, 512, 1024 or 2048
*/

int main(int argc, char* argv[]) {

	int pageSize, mem;
	char rw;
	
	if (argc!=2) {
		fprintf(stderr,"Usage: ./pageRefGen 64|128|256|512|1024|2048\n");
		exit(0);
	}
	
	pageSize=atoi(argv[1]);
	ungetc(' ',stdin);
	
	while (1) {
		scanf(" %c %i", &rw, &mem);
		printf("%c %i\n", rw, mem/pageSize);
		if (rw=='F') exit(0);
	}
}
