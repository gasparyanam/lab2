#include <iostream>
#include <cstring>
using namespace std;

struct worker
{
    char surname[15];
    char name[15];
    int salary;
};

class Base1
{
    private:
        worker* p;
        int n;
        friend class Base2;
    public:
        Base1(int n1)
        {
            cout << "\n-----Constructor-----\n";
            n = n1;
            p = new worker[n];
            if (p == nullptr)
                exit (1);
            for (int i = 0; i < n; i++)
            {
                cout << " Surname " << i << ": ";
                cin >> p[i].surname;
                cout << " Name " << i << ": ";
                cin >> p[i].name;
                cout << " Salary " << i << ": ";
                cin >> p[i].salary;
            }
        }
        ~Base1()
        {
            cout << "\n------Destructor Base1-----\n";
            delete []p;
            p = nullptr;
        }
};

class Base2
{
    public:
        Base2(){}

        
        double MeanSalary(const Base1 &object)
        {
            int Sum = 0;
            for (int i = 0; i < object.n; i++)
            {
                Sum += object.p[i].salary;
            }
            return Sum / object.n;
        }

        void get_HighSalaryList(const Base1 &object)
        {
            double mean = MeanSalary(object);
            int count = 0;
            for(int i = 0; i < object.n; i++)
            {
                if (object.p[i].salary > mean)
                count++;
            }
            if (count == 0)
            {
                cout << "All workers earn less than mean salary" << endl;
                return;
            }
            worker *newlist;
            newlist = new worker [count];
            count = 0;
            for (int i = 0; i < object.n; i++)
            {
                if (object.p[i].salary > mean)
                {
                    newlist[count++] = object.p[i];
                }
            }
            
            for (int i = 0; i < count; i++)
            cout << newlist[i].surname << " " 
            << newlist[i].name << " " 
            << newlist[i].salary << endl;
            delete []newlist;
            newlist = nullptr;
        }

        ~Base2()
        {
            cout << "\n-------Destructor Base2----------\n";
        
        }
};

int main()
{
    int nn;
    do
    {
        cout << "n = ";
        cin >> nn;
    } while (nn < 2 || nn > 50);

    Base1 CretedList(nn);
    Base2 List;
    List.MeanSalary(CretedList);
    List.get_HighSalaryList(CretedList);

    return 0;
}
