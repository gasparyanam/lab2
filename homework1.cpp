#include <iostream>
using namespace std;

struct students
{
    char name[10];
    char surname[15];
    double grade;
};

class studentlist
{
    private:
        students* x;
        int n;
        static int pos_grade;
        static int neg_grade;
    public:
        studentlist(int n1)
        {
            n = n1;
            x = new students[n];
            if (x == nullptr)
            {
                cout << "no memory" << endl;
                exit (1);
            }
            for (int i = 0; i < n; i++)
            {
                cout << "student name: ";
                cin >> x[i].name;
                cout << "student surname: ";
                cin >> x[i].surname;
                cout << "student grade: ";
                cin >> x[i].grade;
                if (x[i].grade > 50)
                    pos_grade++;
                else 
                    neg_grade++;
            }
        }
        ~studentlist()
        {
            delete[]x;
            x = nullptr;
        }
        void positivegrade()
        {
            int count;

            count = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i].grade > 50)
                {
                    cout << x[i].name << " " << x[i].surname << endl;
                    count++;
                }
            }
            if (count == 0)
                cout << "Everyone got a bad grade" << endl;
        }
        static int total_pos_grade()
        {
            return (pos_grade);
        }
        static int total_neg_grade()
        {
            return (neg_grade);
        }
};

int studentlist::pos_grade = 0;
int studentlist::neg_grade = 0;

int main()
{
    int n_1;
    int n_2;
    int n_3;
    do
    {
        cout << "all students count for group 1: ";
        cin >> n_1;
    } while (n_1 < 2);
    
    do
    {
        cout << "all students count for group 2: ";
        cin >> n_2;
    } while (n_2 < 2);
    
    do
    {
        cout << "all students count for group 3: ";
        cin >> n_3;
    } while (n_3 < 2);

    studentlist object1(n_1);
    studentlist object2(n_2);
    studentlist object3(n_3);
    cout << "Total positive grade: " << studentlist::total_pos_grade() << endl;
    cout << "Total negative grade: " << studentlist::total_neg_grade() << endl;
    cout << "Student with positive grade g1:" << endl;
    object1.positivegrade();
    cout << "Student with positive grade g2:" << endl;
    object2.positivegrade();
    cout << "Student with positive grade g3:" << endl;
    object3.positivegrade();
    return (0);
}