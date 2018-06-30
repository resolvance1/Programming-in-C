#include <stdlib.h>				//David Schmidt 5/17/2018
#include <stdio.h>

void main()
{
	double speed;
	printf("What is your speed?");
	scanf("%lf",&speed);//wait for input on speed
	if (speed >65)//if statement to check speed
	{
	printf("SPEEDING\n");
	}
	else //else statement for if statement isn't true
	{
	printf("OK\n");
	}
}
