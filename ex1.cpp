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
		static double TotalDiametr()
		{
			return (diametr);
		}
		~circle(){}
		
};

double circle::diametr = 0;

int	main()
{
	circle circle1(6#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int
    return 0;
});
	circle circle2(7);
	circle circle3(8);

	cout << circle1.Area() << endl;
	cout << circle2.Area() << endl;
	cout << circle3.Area() << endl;
	double totalPerimetr = (circle::Diametr() + circle::Diametr() + circle::Diametr()) * 3.14;
	
	cout << circle::Diametr() * 3.14 << endl;	
	return (0);
}
