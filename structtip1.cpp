#include <iostream>
using namespace std;

struct worker {
    char name[10];
    char surname[15];
    int ch_number;
};

class work {
    private:
        worker* x;
        int n;
        static int count;
    public:
        work(int n1){
            n = n1;
            x = new worker[n];
            if(x == nullptr){
                cout << "NO_MEMORY" << endl;
                exit (1);
            }
            for(int i = 0; i < n; i++){
                cout << i << " worker name: ";
                cin >> x[i].name;
                cout << i << " worker surname: ";
                cin >> x[i].surname;
                cout << i << " worker children: ";
                cin >> x[i].ch_number;
                if(x[i].ch_number != 0)
                count ++;
            }
        }
        ~work(){
            delete []x;
            x = nullptr;
        }
        void print(){
            for(int i = 0; i < n; i++){
                if(x[i].name[0] == 'A'){
                    cout << x[i].name << " " << x[i].surname << endl;
                }    
            }
        }
        static int totalcount()
        {
            return count;
        }
};

int work::count = 0;

int main(){
    int nn;
    do{
        cout << " n = ";
        cin >> nn;
    } while (nn < 2 || nn > 20);
    work object1(nn);
    cout << "Total children: " << work::totalcount() << endl;
    object1.print();

    return 0;
}