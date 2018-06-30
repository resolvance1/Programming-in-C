#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "screenlib.h"
#include <unistd.h>


void getPattern(Screen, FILE *);

int main(int argc, char** argv)
{
  if(argc !=  4)
  {
    printf("Usage: <int width> <int height> <filename for pattern>\n");
    return 1;
  }
  FILE *in = fopen(argv[3], "r");
  if (in == NULL)
  {
    printf("Unable to open %s\n", argv[3]);
    return 1;
  }

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  int x, y;
  int liveN;
  Screen s1, s2;
  s1 = newScreen(width, height, ' ');
  s2 = newScreen(width, height, ' ');
  
  getPattern(s1, in);
  fclose(in);
  printScreen(s1);
  int k;
  int HOWMANY = 1000;
  for (k = 0; k < HOWMANY; k++) 
  {
    for (y = 0; y < height; y++)
    {
      for (x = 0; x < width; x++)
      {
        liveN = findLiveNeighbors(s1, x, y);
        char c = getPixel(s1, x, y);
        if (c == ' ') //currently dead
        {
          if(liveN == 3)
          {
            setPixel(s2, x, y, '*'); //come alive
          }
          else
          {
            setPixel(s2, x, y, ' '); //stay dead
          }
        }
        else //curently alive
        {
          if (liveN == 2 || liveN == 3)
          {
            setPixel(s2, x, y, '*'); //say alive
          }
          else
          {
            setPixel(s2, x, y, ' '); //die
          }
        }
      } // for x
    } // for y
    Screen temp = s1;
    s1 = s2;
    s2 = temp;
    printScreen(s1);
    usleep(100*1000);
  }
  freeScreen(s1);
  freeScreen(s2);
}  

void getPattern(Screen s, FILE *in)
{
  int maxw = getWidth(s);
  int maxh = getHeight(s);
  int x = 0;
  int y = 0;
  char c;
  int cnt = fscanf(in, "%c", &c);
  while (cnt > 0)
  {
    x = 0;
    while (c != '\n')
    {
      setPixel(s, x, y, c);
      cnt = fscanf(in, "%c", &c);
      x++;
    }
    cnt = fscanf(in, "%c", &c);
    y++;
  }    
}  

int findLiveNeighbors(Screen s, int x, int y)
{
  int count = 0;
  int xx, yy;
  for(xx = x-1; xx <= x+1; xx++)
  {
    for(yy = y-1; yy <= y+1; yy++)
    {
      if((xx != x || yy != y) && getPixel(s, xx, yy) != ' ')
      {
        count++;
      }
    }
  }
  return count;
}

