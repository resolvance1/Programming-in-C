#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct data
{
  double weight;
  double disp;
}Data;


int getWeights (Data[]);
int main(void)
{
	Data info[300];
	
	int count = getWeights(info);
	int i;
	for (i = 0; i < count; i++)
	{
	  printf("%7.2lf %7.2lf\n", info[i].weight, info[i].disp);
	}
}

int getWeights(Data w[])
{
	int retval=0;
	double temp;
	printf("Enter first weight (or -1 to quit) : ");
	scanf("%lf", &temp);
	while (temp>0)
	{
	 w[retval].weight = temp;
	 printf("Enter displacemnet" );
	 scanf("%lf", &temp);
	 w[retval].disp = temp;
	 retval++;
	 scanf("%lf", &temp);
	}
	return retval;
}
