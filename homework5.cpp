#include <iostream>
using namespace std;

struct student
{
    char surname[15];
    int pension;
    double grade;
};

class Studentlist
{
    protected:
        student *x;
        int n;
    public:
        Studentlist(student *x1, int n1)
        {
            x = x1;
            n = n1;
        }
        double average_grade()
        {
            double sum;
            sum  = 0;
            for (int i = 0; i < n; i++)
                sum += x[i].grade;
            return (sum / n);
        }
};

class NewStudentList : public Studentlist
{
    public:
        NewStudentList(student *x1, int n1) : Studentlist(x1, n1)
        {
        }
        
        void pension_rise()
        {
            for (int i = 0; i < n; i++)
            {
                if (x[i].grade > average_grade())
                    x[i].pension = 10000;
            }
        }

        void print()
        {
            pension_rise();
            for (int i = 0; i < n; i++)
            {
                cout << x[i].surname << " " << x[i].grade << " " << x[i].pension << endl;
            }
        }
};

int main()
{
    student xx[50];
    int nn;
    do
    {
        cout << "Usanoxneri qanak: ";
        cin >> nn;
    } while (nn < 2 || nn > 50);

    for (int i = 0; i < nn; i++)
    {
        cout << "Azganun: ";
        cin >> xx[i].surname;
        cout << "Toshaki chapy: ";
        cin >> xx[i].pension;
        cout << "Gnahatakny: ";
        cin >> xx[i].grade;
    }
    
    NewStudentList list1(xx, nn);

    list1.print();
    return 0;
}