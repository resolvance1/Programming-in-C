#include <stdlib.h>		      	//David Schmidt 5/17/2018
#include <stdio.h>

void main()
{
	double a,b,c;//Initialize floats
	double per;
	double area;
	
	printf("Hello!\nThis program helps you find if three line lengths make up a triangle \nPlease input the 3 sides of the triangle\n");
	scanf("%lf",&a);//prompt user for sides of triangles
	scanf("%lf",&b);
	scanf("%lf",&c);
	per = (a + b + c) / 2.0;//perimeter and area equations
	area = per * ( per - a ) * ( per - b ) * ( per - c );
	

	 if (((a+c)>b)&& ((a+b)>c)&&((b+c)>a))//If state for proving it can make a triangle
	{
	 printf("TRIANGLE\n");
 	 printf("Perimeter is %lf and area is %lf\n",per,area);
	}

	else //Else statement if it does not constitute a triangle. 
	{
	 printf("NO TRIANGLE\nTry again!\n");
	}
	
}
