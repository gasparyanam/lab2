#include <iostream>
using namespace std;

struct cnumber
{
    int a;
    int b;
};

class Base
{
    private:
        cnumber* p1;
        cnumber* p2;
        cnumber x[30];
        int n;
    public:
        Base(int n1)
        {
            cout << "--Base Constructor--" << endl;
            
            n = n1;
            p1 = new cnumber [n];
            p2 = new cnumber [n];
            if (p1 == nullptr || p1 == nullptr)
                exit (1);
            cout << "P1 complex numbers" << endl;
            for (int i = 0; i < n; i++)
                cin >> p1[i].a >> p1[i].b;

            cout << "P2 complex numbers" << endl;
            for (int i = 0; i < n; i++)
                cin >> p2[i].a >> p2[i].b;
        }

        ~Base()
        {
            cout << "Base Destructor" << endl;
            delete []p1;
            delete []p2;
            p1 = nullptr;
            p2 = nullptr;
        }

        Base(const Base &object1)
        {
            n = object1.n;
            p1 = new cnumber [n];
            p2 = new cnumber [n];
            for (int i = 0; i < n; i++)
            {
                p1[i] = object1.p1[i];
                p2[i] = object1.p2[i];    
            }

        }

        void printX()
        {
            for (int i = 0; i < n; i++)
                cout << x[i].a << " + " << x[i].b << "i" << endl;
        }

        friend void Sum(Base);
        friend void Product(Base&);

};

void Sum(Base object)
{
    for (int i = 0; i < object.n; i++)
    {
        object.x[i].a = object.p1[i].a + object.p2[i].a;
        object.x[i].b = object.p1[i].b + object.p2[i].b;
    }
    object.printX();
}

void Product(Base &object)
{
    for (int i = 0; i < object.n; i++)
    {
        object.x[i].a = object.p1[i].a * object.p2[i].a;
        object.x[i].b = object.p1[i].b * object.p2[i].b;
    }
}

int main()
{
    int n1;
    do
    {
        cout << "n = ";
        cin >> n1;
    } while (n1 < 2 || n1 > 30);

    Base object(n1);
    cout << "New complex array with Product" << endl;
    Product(object);
    object.printX();
    cout << "New complex array with Sum" << endl;
    Sum(object);
    return 0;
}