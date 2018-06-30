#include <stdlib.h>				//David Schmidt 5/17/2018
#include <stdio.h>

void main()
{
	int temp;//intialize temp integer
	
	printf("How hot is the soup?\n:");
	scanf("%d",&temp);//input data
	if (temp > 160)//Check to see if temp is greater than 160
	{
	 printf("This soup is too hot\n");
	}
	if (temp < 120)// Check to see if temp is below 120  
	{
	 printf("This soup is too cold\n"); 
	}
	if (temp >= 120 && temp <= 160)//Check to see if temp is between desired values 
	{
	 printf("This soup is just right.\n");
	}
}
