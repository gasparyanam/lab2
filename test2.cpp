#include <iostream>
using namespace std;

class QuadraticEquation {
private:
    double *a, *b, *c;
    static double negativeSum;

public:
    QuadraticEquation(double a_val, double b_val, double c_val) {
        a = new double(a_val);
        b = new double(b_val);
        c = new double(c_val);

        if (*a < 0) negativeSum += *a;
        if (*b < 0) negativeSum += *b;
        if (*c < 0) negativeSum += *c;
    }
    ~QuadraticEquation() {
        delete a;
        delete b;
        delete c;
        cout << "Object destroyed" << endl;
    }

    double discriminant(){
        return (*b) * (*b) - 4 * (*a) * (*c);
    }

    static double getNegativeSum() {
        return negativeSum;
    }

    void printCoefficients(){
        cout << "a=" << *a << ", b=" << *b << ", c=" << *c;
    }
};

double QuadraticEquation::negativeSum;

int main() {
    QuadraticEquation eq1(1, -3, 2);
    QuadraticEquation eq2(-2, 5, -3);
    QuadraticEquation eq3(4, 0, -9);

    cout << "Equation 1 ("; eq1.printCoefficients();
    cout << ") discriminant: " << eq1.discriminant() << endl;

    cout << "Equation 2 ("; eq2.printCoefficients();
    cout << ") discriminant: " << eq2.discriminant() << endl;

    cout << "Equation 3 ("; eq3.printCoefficients();
    cout << ") discriminant: " << eq3.discriminant() << endl;

    cout << "\nSum of all negative coefficients: "
         << QuadraticEquation::getNegativeSum() << endl;

    return 0;
}