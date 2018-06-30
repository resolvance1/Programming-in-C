#include <stdlib.h>
#include <stdio.h>

int colors2r(char ** colors)
{

  int c1 = stringn2num(colors[0]);
  int c2 = stringn2num(colors[1]);
  int c3 = stringn2num(colors[2]);
  int i;

  int retval = 10 * c1 + c2;]
  for (i = 0; i < c3; i++)
  {
    retval *= 10;
  }
  return retval;
}

int string2num ( char color[])
{
  char c [10][10]  = {"BLACK" , "BROWN", "RED", " ORANGE", "YELLOW", "GREEN", "BLUE", "VIOLET", "GREY", "WHITE",};

  int i;
  for(i = 0; i< 10; i++)
  {
    if(strcmp(color, c[i]) == 0)
    {
      return i;
    }
  }
  printf(" Ileegal color %s", color);
  exit(1);
}

int main(void)
{
  char  colors[10][10] = {"RED", "VIOLET", "GREEN"};

  int ohms = colors2r(colors);
  printf("%d\n",ohms);
}

