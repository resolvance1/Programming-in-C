#include <stdlib.h>
#include <stdio.h>

void main()
{
	int getInt(int, int);
	int getIntInRange(char[], int, int);

	int ave;
	int a, b, c;
	a = getInt("Enter an integer:"10,100);
	b = getInt(a,100);
	c = getInt(17,35);
	ave = ( a + b + c ) / 3; 
	printf ("%d %d %d %d\n", a, b, c, ave); 
}

	int getInt()
	{
	int retval;
	printf("Enter an integer:");
	scanf("%d", &retval);
	return retval;
	}

	int getIntInRange(int min, int max)
{	
	int retval;
	printf("Enter an integer");
	scanf("%d", retval);
	
	while (retval < min || retval > max)
	{
	  printf("%d is NOT between %d and %d. Try again \n", retval, min, max);
	  printf("Enter an integer between %d and $d :", min, max);
	  scanf("%d", &retval);
	}
	return retval;
}
	int getIntInRangePrompt (char prompt[], int min, int max)
	{
	int retval;
	printf("%s",prompt);
	retval = getIntInRange(min , max);
	return retval;
	}
