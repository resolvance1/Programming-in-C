#include <stdlib.h>
#include <stdio.h>

void main()

{
	unsigned int isize, dsize, csize, ldsize, lsize;
	isize = sizeof(int);
	dsize = sizeof(double);
	csize = sizeof(char);
	ldsize = sizeof(long double);
	lsize = sizeof(long);
	printf("int %u, double %u, char %u\n", isize, dsize, csize);
	printf("long %u, long double %u\n",lsize, ldsize);
}
