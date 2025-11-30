#include <iostream>
using namespace std;

class Baz 
{
	protected:
		double *x;
		int n;
	public:
		Baz(double *x1, int n1)
		{
			x = x1;
			n = n1;
		}
		~Baz(){}

		void element_output()
		{
			for (int i = 0; i < n; i++)
			{
				cout << x[i] << endl;
			}
		}

		double positive_elementSum()
		{
			double Sum;
			Sum = 0;
			for (int i = 0; i < n; i++)
			{
				if(x[i] > 0)
					Sum += x[i];				
			}
			return (Sum);
		}
		
};

class Jarang1 : public Baz
{
	private:
		double a;
	public:
		Jarang1(double *x1, int n1, double a1) : Baz(x1, n1)
		{
			a = a1;
		}

		void add_a()
		{
			for (int i = 0; i < n; i++)
			{
				x[i] += a;
			}
		}
		~Jarang1(){}
};

class Jarang2 : public Baz
{
	public:
		Jarang2(double *x1, int n1) : Baz(x1, n1){}
	
		void double_arr()
		{
			for (int i = 0; i < n; i++)
			{
				x[i] *= 2;
			}			
		}
		~Jarang2(){};
};

int main()
{
	double xx[50];
	int nn;
	do{
		cout << "n = ";
		cin >> nn;
	} while (nn < 2 || nn > 50);
	
	for (int i = 0; i < nn; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> xx[i];
	}
	double a;
	cout << "a = ";
	cin >> a;
	
	Jarang1 obj1(xx, nn, a);
	Jarang2 obj2(xx, nn);
	obj1.element_output();
	obj1.add_a();
	obj1.element_output();
	obj2.double_arr();
	return 0;
}
