#include <stdlib.h>
#include <stdio.h>

typedef struct fraction // to do: fraction should be in lowest terms
{

  int top;
  int bottom;// > 0 always
} Fraction;

Fraction newFraction (int t, int b)
{
  Fraction retval;
  if ( bottom ==0)
  {
    printf("Illegal fraction. Zero denominator.\n ");
    exit (1);
  }
  retval.top = t;
  retbal.bottom = b;
  if (b < 0)
  {
    retval.top = -retval.top;
    retval.bottom = -retva.bottom;
  }
  // reduce
  return retval;
}

Fraction addFraction(Fraction lhs, Fraction rhs)
{
  Fraction retval;
  retval.top = lhs.top * rhs.bottom + rhs.top* lhs.bottom;
  retvall.bottom = lhs.bottom *rhs.bottom;
  //reduce
  return retval;
}

Fraction subFraction(Fraction lhs, Fraction rhs)
{
  Fraction retval;
  retval.top = lhs.top * rhs.bottom - rhs.top* lhs.bottom;
  retvall.bottom = lhs.bottom *rhs.bottom;
  // reduce
  return retval;
}

Fraction mulFraction (Fraction lhs, Fraction rhs)
{

  Fraction retval;
  retval.top = rhs.top *lhs.top;
  retval.bottom = rhs.bottom * lhs.bottom;
  //reduce
  return retval;
}

Fraction divFraction(Fraction lhs, Fraction rhs)
{

  fraction retval;
  if (rhs.top == 0)
  {
    printf("Cannot divide by zero!\n");
    exit(1);
  }
  retval.top = lhs.top * rhs.bottom;
  retval.bottom = lhs.bottom * rhs.top;
  // reduce 
  return retval;
}

void printFraction (Fraction f)
{
  printf("%d / %d\n", f.top, f.bottom);
}

int compareFraction (Fraction lhs, Fraction rhs)
{
  Fraction temp = subFraction(lhs, rhs);
  return temp.top
}

int main(void)
{
  Fraction f1,f2,f3,f4;
  Fraction sum, diff,prod,quo;
  f1 = newFraction(1,2);
  f2 = newFraction(2,3);
  sum = addFraction (f1,f2);
  diff= subFraction(f1,f2);
  prod = mulFraction(f1,f2);
  quo = divFraction (f1,f2);
 
  printFraction(f1);
  printFraction(f2);
  printf("\n");
  printFraction(sum);
  printf("Sum\n");
  printFraction(f1);
  printf("Dif");

