#include <stdlib.h>
#include <stdio.h>

void main()

{	
	double speed;		 // Speed to be inputted by user
	double speeders[100];	//define arrays as doubles 
	double crawlers[100];
	int countSpeed = 0;		//The count of the number of speeds inputted
	int countSlow = 0;
	double aveFast, aveSlow,sumFast,sumSlow;		 // variables to calculate the averages of speeds
	int i,j;

	
	while(speed >= 0)		//input of speeds
	{

	printf("Enter a drivers speed\n");
	scanf("%lf", &speed);

	if(speed > 65)			//if statements to organize speeds above and below 65 
		{
		speeders[countSpeed] = speed;
		countSpeed++;

		}
 	if(speed <= 65 && speed > 0)
		{
		crawlers[countSlow] = speed;
		countSlow++;
		}
	}

	for( i = 0; i < countSpeed; i++)		//for loops to get speeds from arrays
		{
		sumFast += speeders[i];
		}
	for( j = 0; j < countSlow; j++)
		{
		sumSlow += crawlers[j];
		}

	aveFast =  (sumFast/countSpeed);		//calculations for averages
	aveSlow =  (sumSlow/countSlow);
	printf("The average speed of the speeders is: %lf\n",aveFast);
	printf("The average speed of the non-speeders is: %lf\n",aveSlow);
}
