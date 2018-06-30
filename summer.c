#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int sum, i, n;
  printf("Enter a positive integer");
  scanf("%d", &n);
  while(n <= 0)
  {
    printf("You did not pay attention. Enter a POSITIVE integer:");
    scanf("%d", &n);
  }
  
  sum = addup2(n);
}
int addup (int n)
{
  int sum;
  int i;
  int retval = 0;
  for (i =1; i<= n; i++)
  {
   sum = sum +i;
  }
  printf("The sum is %d", sum);

int addup2(int k)
{
 if (k ==1)
 {
  retval = 1;
 }
 else 
 {
   retval = addup(k-1) + k;
 } 
 return retval;
}
}
