#include <stdlib.h>
#include <stdio.h>

int main (void)

{

	int x;
	int *xp;
	x = 10;
	xp = &x;
	printf("x contains %d\n",x);
	printf("&xp contains %d\n", *xp);
	printf("xp contains %p\n", xp);
	printf("%d\n", *(&x));
}
