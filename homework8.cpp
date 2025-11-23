#include <iostream>
using namespace std;

class Base1
{
    protected:
        double *x;
        int n;
    public:
        Base1 (double *x1, int n1)
        {
            cout << "Constructor B1" << endl;
            x = x1;
            n = n1;
        }
        ~Base1()
        {
            cout << "Destructor B1" << endl; 
        }
        double max_member()
        {
            double max;
            max = x[0];
            for (int i = 0; i < n; i++)
            {
                if (x[i] > max)
                    max = x[i];
            }    
            return max;
        }
};

class Base2
{
    protected:
        double *y;
        int m;
    public:
        Base2(double *y1, int m1)
        {
            cout << "Constructor B1" << endl;
            y = y1;
            m = m1;
        }
        ~Base2()
        {
            cout << "Destructor B2" << endl;
        }

        double posProduct()
        {
            double P;
            P = 1;
            for (int i = 0; i < m; i++)
            {
                if (y[i] < 0)
                    P *= y[i];
            }
            return P;
        }
};

class Derived : public Base1, public Base2
{
    public:
        Derived(double *x1, int n1, double *y1, int m1) : Base1(x1, n1), Base2(y1, m1)
        {
            cout << "Derived constructor" << endl;
        }
        ~Derived()
        {
            cout << "Derived destructor" << endl;
        }
        void foo()
        {
            double f1 = max_member();
            double f2 = posProduct();
            if (f1 > f2)
                cout << f1 << endl;
            else 
                cout << f2 << endl;
        }
};

int main()
{
    int nn, mm;
    double xx[50], yy[50];
    do
    {
        cout << "n = ";
        cin >> nn;
    } while (nn < 2 || nn> 50);

    for (int i = 0; i < nn; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> xx[i];
    }

    do
    {
        cout << "m = ";
        cin >> mm;
    } while (mm < 2 || mm > 50);

    for (int i = 0; i < mm; i++)
    {
        cout << "y[" << i << "] = ";
        cin >> yy[i];
    }
    Derived object1(xx, nn, yy, mm);

    object1.foo();

    return 0;
}