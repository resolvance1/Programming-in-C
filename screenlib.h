typedef struct line
{
  int width;
  char* theLine;
} Line;

typedef struct screen
{
  int width;
  int height;
  Line* theScreen;
} Screen;
  
Line newLine(int width, char fill);
Screen newScreen(int width, int height, char fill);
void printLine(Line line);
void printScreen(Screen scr);
void setLinPixel(Line lin, int x, char c);
void setPixel(Screen s, int x, int y, char c);
char getLinPixel(Line lin, int x);
char getPixel(Screen s, int x, int y);
void hline(Screen s, int x1, int x2, int y, char c);
void vline(Screen s, int x, int y1, int y2, char c);
void writeString(Screen s, int x, int y, char str[]);
int getWidth(Screen);
int getHeight(Screen);
void drawRect(Screen s, int x1, int y1, int x2, int y2, char c);
