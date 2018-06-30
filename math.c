#include <stdlib.h>
#include <stdio.h>

void main()
{
	int x;
	printf("Enter a positive number");
	scanf("%d", &x);

	while (x>0)
	{
	 printf("%d", x %10 );
	 x = x /10;
	}
	printf("\n");
}
