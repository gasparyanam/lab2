#include <iostream>
#include <cstring>
using namespace std;

struct student
{
    char surname[15];
    int pension;
    int grade;
};

class Base 
{
    protected:
        student *x;
        int n;
    public:
        Base(student *x1, int n1)
        {
            x = x1;
            n = n1;
        }
};

class Jar1 : protected Base
{
    public:
        Jar1(student *x1, int n1) : Base(x1, n1) {}

        student* getExcellentList(int &k)
        {

            k = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i].grade >= 50)
                    k++;
            }
            student *y = new student [k];
            if (y == nullptr)
                exit (1);
            
            int q = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i].grade > 50)
                {
                    strcpy(y[q].surname, x[i].surname);
                    y[q].pension = x[i].pension + 10000;
                    y[q].grade = x[i].grade;
                    q++;
                }
            }
            return y;
        }
};

class Jar2 : private Jar1
{

    public:
        Jar2(student *x1, int n1) : Jar1(x1, n1) {}

        void printnewlist()
        {
            int count;
            
            student *w = getExcellentList(count);
            
            if(count == 0)
            {
                cout << "0 Excellent students" << endl;
                return;
            }

            cout << "New List" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << w[i].surname << " " << w[i].pension << " " << w[i].grade << endl;
            }

            delete []w;
            w = nullptr;
        }
};

int main()
{
    student xx[50];
    int nn;
    do{
        cout << "n = ";
        cin >> nn;
    } while (nn < 2 || nn > 50);

    for (int i = 0; i < nn; i++)
    {
        cout << "Surname: ";
        cin >> xx[i].surname;
        cout << "Pension: ";
        cin >> xx[i].pension;
        cout << "Grade: ";
        cin >> xx[i].grade; 
    }
    Jar2 object(xx, nn);
    object.printnewlist();

    return 0;
}