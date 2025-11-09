#include <iostream>
using namespace std;

class arr
{
    private:
        double *x;
        int n;
    public:
        static double Sum_arr;
        arr(int n1)
        {
            n = n1;
            x = new double [n];
            if (x == nullptr)
            {
                cout << "No Memory" << endl;
                exit (1);
            }
            for(int i = 0; i < n; i++)
            {
                cout << "x[" << i << "] = ";
                cin >> x[i];
                Sum_arr += x[i];
            }
        }

        double pos_sum(int *count)
        {
            *count = 0;
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                if(x[i] > 0)
                    sum += x[i];
                    (*count)++;
            }
            return sum;
        }

        ~arr()
        {
            delete []x;
            x = nullptr;
        }

        static double totalsum()
        {
            return Sum_arr;
        }
};

double arr::Sum_arr = 0;

int main()
{
    int n_1;
    int n_2;
    int n_3;
    int n_4;
    int count;
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
    do
    {
        cout << "n4 = ";
        cin >> n_4;
    } while (n_4 < 2);
    arr object1(n_1);
    arr object2(n_2);
    arr object3(n_3);
    arr object4(n_4);
    cout << "Arith mean 1: ";
    cout << (object1.pos_sum(&count)) / count << endl;
    cout << "Arith mean 2: ";
    cout << (object2.pos_sum(&count)) / count<< endl;
    cout << "Arith mean 3: ";
    cout << (object3.pos_sum(&count)) / count << endl;
    cout << "Arith mean 4: ";
    cout << (object4.pos_sum(&count)) / count << endl;
    cout << "Total Sum: " << arr::totalsum() << endl;
    return (0);
}