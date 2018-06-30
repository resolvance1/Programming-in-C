public class Function
{
  private int top;
  private int bottom;

  public Fraction (int t, int b)
  {
    if( b == 0 )
    {
      System.out.println("Invalid fraction.");
      System.exit(1);
    }
    if( t < 0)
    {
      t = -t;
      b = -b;
    }
    top = t;
    bottom = b;
  }
  Fraction add(Fraction rhs)
  {
    Fraction retval;
    retval.top = this.top * rhs.bottom + this.bottom * rhs.top;
    retval.bottom = this.bottom * rhs.bottom;
    return retval;
  }

  public String toString()
  {
    return this.top + "/" + this.bottom;
  }








  public static void main(String args[])
  {
    Fraction f1 = new Fraction (1, 2);
    Fraction f2 = new Fraction (2,3);

    Fraction f3 = f1.add(f2);
    
    System.out
  }
