#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
	double a,b, hypot, sum;
	printf("Enter side 1 of a right triangle");
	scanf("%lf",&a);
	printf("Enter side 2 of a right triangle");
	scanf("%lf", &b);
	sum =((a*a) + (b*b));
	hypot = sqrt(sum);
	printf("3rd side is equal to %lf\n",hypot); 
return(1);
}

