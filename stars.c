include <stdlib.h>
include <stdio.h>

int main(void)
{
  int n ;
  printf("Enter a positive integer:");
  scanf("%d", &n);

  stars(n):
}

void stars(int k)
{
  if( k==1)
  {
    printf("*\n");
  }

  else 
  {
    stars(k-1);
    for (i = 0; i< k; i++)
    {
      printf("*");
    }
    print("\n");
    stars(k-1);
  }
}

