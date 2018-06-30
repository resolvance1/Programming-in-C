#include <stdlib.h>
#include <stdio.h>
void intout(int);
int main(void)
{
  int n;
  printf("Enter a positive integer:");
  scanf("%d", &n);
  intout(n);
  printf("\n");
}

void intout(int k)
{
  int r;
  int b = 10;
  if (k < b)
  {
    char c = '0' + k; 
    printf("%c", c);
  }
  else 
  {
    intout(k/b);
    intout(k % b);
  }
}
