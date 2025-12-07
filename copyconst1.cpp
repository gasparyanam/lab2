#include <iostream>
using namespace std;

class Foo {

    public:
        int bar;
        char* buffer;

        Foo() {
            std::cout << "constructor\n";
            buffer = new char[6];
            buffer[0] = 'h';
            buffer[1] = 'e';
            buffer[2] = 'l';
            buffer[3] = 'l';
            buffer[4] = 'o';
            buffer[5] = '\0';
        }
        Foo(const Foo &miusObj) {
            bar = miusObj.bar;
            buffer = new char[6];
            for(int i = 0; i < 6; i++)
            {
                buffer[i] = miusObj.buffer[i];
            }
        }

        ~Foo()
        {
            delete[] buffer;
        }
};

void func(Foo &b) {
    b.bar = 100;
    b.buffer[0] = 'a';
}

int main() {
    Foo a;
    a.bar = 10;
    func(a);
    cout << a.buffer << endl;
}