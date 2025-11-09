#include <iostream>
using namespace std;

struct student{
    char name[10];
    char surname[15];
    double examgrade;
};

class studentlist{
    private:
        student *x;
        int n;
        static int count_posgrade;
    public:
        studentlist(int n1){
            n = n1;
            x = new student [n];
            if (x == nullptr){
                cout << "NO MEMORY";
                exit (1);
            }
            for(int i = 0; i < n; i++){
                cout << i << " student name: ";
                cin >> x[i].name;
                cout << i << " student surname: ";
                cin >> x[i].surname;
                cout << i << " student grade: ";
                cin >> x[i].examgrade;
            }
            for(int i = 0; i < n; i++){
                if(x[i].examgrade >= 50){
                    count_posgrade++;
                }
            }
        }
        ~studentlist(){
            delete []x;
            x = nullptr;
        }
        int posgrade(){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(x[i].examgrade >= 50)
                    count++;
            }
            return count;
        }
        static int totalcount(){
            return count_posgrade;
        }
};
int studentlist::count_posgrade = 0;
int main(){
    int nn;
    do{
        cout << " n = ";
        cin >> nn;
    } while (nn < 2 || nn > 30);
    studentlist object1(nn);
    cout << "Total count of positive grades: " << studentlist::totalcount() << endl;
    cout << "total from any group count: " << object1.posgrade() << endl;
    return 0;
}