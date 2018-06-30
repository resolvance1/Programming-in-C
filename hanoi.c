#include <stdlib.h>
#include <stdio.h>

void hanoi(int n, int src, int dest);

int main(void)
{
  int n, start, end;
  printf("How many disks:");
  scanf("%d", &n);
  printf("Starting tower (0,1, or 2) :");
  scanf("%d", &start);
  printf("Ending tower (0,1, or 2):");
  scanf("%d", &end);
  hanoi( n, start, end);
}

void hanoi( int n, int src, int dest)
{
  int other = 3 - src - dest;
  if (n == 1 )
  {
    printf("move a disk from %d to %d\n", src, dest);
  }
  else 
  {
    hanoi(n-1, src, other);
    hanoi(1 , src,dest);
    hanoi(n-1, other, dest);
  }
}
