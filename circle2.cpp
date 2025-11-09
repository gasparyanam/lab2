#include <iostream>

using namespace std;

class circle
{
  private:
    double radius;
    static double diametr;
  public:
    circle (double r)
    {
      radius = r;
      diametr += 2 * r;
    }
    double Area()
    {
      return (radius * radius * 3.14);  
    }
    double Perimetr()
    {
      return (diametr * 3.14);
    }
    static double Diametr()
    {
      return (diametr);
    }
    
};

double circle::diametr = 0;

int  main()
{
  circle circle1(6);
  circle circle2(7);
  circle circle3(8);

  cout << circle1.Area() << endl;
  cout << circle2.Area() << endl;
  cout << circle3.Area() << endl;
  //double totalPerimetr = circle1.Perimetr() + circle2.Perimetr() + circle3.Perimetr();
  
  cout << circle2.Perimetr() << endl;  
  return (0);
}