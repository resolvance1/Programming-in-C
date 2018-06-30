
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "screenlib.h"

Line newLine(int width, char fill)
{
  int x;
  Line retval;
  retval.width = width;
  retval.theLine = (char *)malloc(width*sizeof(char)+1);
  for(x =0; x < width; x++)
    retval.theLine[x] = fill;
  retval.theLine[width] = 0;
  return retval;
}

void freeLine(Line lin)
{
  free(lin.theLine);
}

/*void drawRect(Screen s, int x1, int y1, int x2, int y2, char c)
{
  int i;
  Screen retval;
  retval.width = 

}*/


Screen newScreen(int w, int h, char fill)
{
  int i;
  Screen retval;
  retval.width = w;
  retval.height = h;
  printf("h * sizeof(Line) = %ld\n", h*sizeof(Line));
  retval.theScreen = (Line*)malloc(h * sizeof(Line));
  for (i = 0; i < h; i++)
    retval.theScreen[i] = newLine(w, fill);
  return retval;
}

void freeScreen(Screen s)
{
  int i;
  for (i = 0; i < s.height; i++)
  {
    freeLine(s.theScreen[i]);
  }
  free(s.theScreen);
}
void printLine(Line line)
{
  printf("%s\n", line.theLine);
}

void printScreen(Screen scr)
{
  int y;
  for (y = 0; y < scr.height; y++)
  {
    printLine(scr.theScreen[y]);
  }
}

int getWidth(Screen s)
{
  return s.width;
}

int getHeight(Screen s)
{
  return s.height;
}

void setLinPixel(Line lin, int x, char c)
{
  if (x < lin.width && x >= 0)
  {
    lin.theLine[x] = c;
  }
}

void setPixel(Screen s, int x, int y, char c)
{
  if (y < s.height && y >= 0)
  {
    setLinPixel(s.theScreen[y], x, c);
  }
}

char getLinPixel(Line lin, int x)
{
  if (x >= 0 && x < lin.width)
  {
    return lin.theLine[x];
  }
  else
  {
    return ' ';
  }
}

char getPixel(Screen s, int x, int y)
{
  if (y >= 0 && y < s.height)
  {
    return getLinPixel(s.theScreen[y], x);
  }
  else
  {
    return ' ';
  }
}

int min(int a, int b)
{
  if (a < b)
    return a;
  else 
    return b;
}

int max(int a, int b)
{
  if (a < b)
    return b;
  else
    return a;
}

void hline(Screen s, int x1, int x2, int y, char c)
{
  int x;
  for (x = min(x1, x2); x <= max(x1, x2); x++)
  {
    setLinPixel(s.theScreen[y], x, c);
  }
}

void vline(Screen s, int x, int y1, int y2, char c)
{
  int y;
  for (y = min(y1, y2); y <= max(y1, y2);  y++)
  {
    setPixel(s, x, y, c);
  }
}

void writeString(Screen s, int x, int y, char str[])
{
  int j;
  int length = strlen(str);
  for (j = 0; j < length; j++)
  {
    setPixel(s, x, y, str[j]);
    x++;
  }
}
int main(void)
{

  char  graph [12];
  FILE *in = fopen("month.dat", "r");//opens file with pregenerated words
  if(in == NULL)
  {
        printf("Unable to open month.dat.\n");//prompts if file can't be opened
        exit(1);
  }
  int j = 0;
  for (j = 0; j < 12; j++)
  {
    fscanf(in, "%lf", (double*)&graph[j]);//searches for characters in file
    printf("\n%lf\n", (double)graph[j]);
  }
  fclose(in);



  int i = 0; 
  Screen scr; 
  scr = newScreen(75,25 , ' ');
  for(i = 0; i < 12; ++i)
  {
    i = i*3;

  hline(scr,i,i+2,graph[i],'*');
  vline(scr,i,1,graph[i],'*');
  vline(scr,i+2,1,graph[i],'*');
  printScreen(scr);
  } 
  freeScreen(scr);
}
