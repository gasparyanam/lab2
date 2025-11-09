#include <iostream>
using namespace std;

class arr
{
    private:
        double *x;
        int n;
        static int ob_count;
    public:
        arr(int n1)
        {
            n = n1;
            x = new double [n];
            if (x == nullptr)
            {
                cout << "No memory" << endl;
                exit (1);
            }
            for (int i = 0; i < n; i++)
            {
                cout << "x[" << i << "] = ";
                cin >> x[i];
            }
            ob_count++;
        }
        ~arr()
        {
            delete []x;
            x = nullptr;
        }
        double min_member()
        {
            double min = x[0];
            for (int i = 1; i < n; i++)
            {
                if (x[i] < min)
                    min = x[i];
            }
            return min;
        }
        static int totalobjects()
        {
            return ob_count;
        } 

};

int arr::ob_count = 0;

int main()
{
    int n_1;
    int n_2;
    int n_3;

    do
    {
        cout << "n1 = ";
        cin >> n_1;
    } while (n_1 < 2);
    do
    {
        cout << "n2 = ";
        cin >> n_2;
    } while (n_2 < 2);
    do
    {
        cout << "n3 = ";
        cin >> n_3;
    } while (n_3 < 2);
    arr object1(n_1);
    arr object2(n_2);
    arr object3(n_3);

    cout << "min member for ob1: ";
    cout << object1.min_member() << endl;
    cout << "min member for ob2: ";
    cout << object2.min_member() << endl;
    cout << "min member for ob3: ";
    cout << object3.min_member() << endl;

    cout << "Total objects count: " << arr::totalobjects() << endl;

    
    return (0);
}