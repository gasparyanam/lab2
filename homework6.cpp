#include <iostream>
using namespace std;

struct student 
{
    char surname[15];
    double grade;
    int absence;
};

class StudentList
{
    protected:
        student *x;
        int n;
    public:
        StudentList(student *x1, int n1)
        {
            x = x1;
            n = n1;
        }
    double max_grade()
    {
        double max;
        max = x[0].grade;
        for (int i = 0; i < n; i++)
        {
            if (x[i].grade > max)
                max = x[i].grade;
        }
        return max;
    }
};

class Student_withmaxgrade : public StudentList
{
    private:
        student *y;
    public:
        Student_withmaxgrade(student *x1, int n1) : StudentList(x1, n1) {}

        void maxgradelist()
        {
            for (int i = 0; i < n; i++)
            {
                if ()
            }
        }
    
}