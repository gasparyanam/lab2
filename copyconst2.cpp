#include <iostream>
using namespace std;

class Base
{
    private:
        int q;
    public:
        int bar;
        Base()
        {
            q = 12;
            cout << "constructor" << endl;
        }
        ~Base()
        {
            cout << "destructor" << endl;
        }
        Base(const Base &objectCopy)
        {
            bar = objectCopy.bar;
            cout << "Copy constructor" << endl;
        }
        void function();
};

void Base :: function()
{
    cout << "------>"<< q << bar << endl;
}

int main()
{
    Base object1;
    object1.bar = 10;
    //function(object1);
    cout << object1.bar << endl;
    object1.function();
    return 0;
}