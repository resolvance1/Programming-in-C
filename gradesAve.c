#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int getscores(double[],int);
double getAverages(double[],int);
void printGrades(double[], double, int);
void main()
{
	double scores[MAX];
	double average;
	int count;

	count = getScores(scores, MAX);
	average = getAverage(scores,count);
	printGrades(scores, averages, count);
}

	int getScores(double s[], int maxNum)
{
	double val;
	int count= 0;
	print("Enter a score (or -1.0 to quit):");
	scanf("%lf" &val);
	while (val >0.0 && count < maxNum)
	{
	 s[count] = val;
	 count++
	 printf("Enter a score ( or -1.0 to quit):");
	 scanf("%lf" &val);
	}
}
	double getAverage(double s[], int num)
{
	double sum = 0.0;
	int i;
	for (i = 0; i< num; i++
	{
	sum = sum + s[i];
	}
	return 
}
	void printGrades(double s[], double ave, int num)
{
	printf("Everyone gets an a\n");
}
