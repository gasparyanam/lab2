#include <iostream>
#include <string.h>
using namespace std;

struct books
{
    char author[20];
    char title[20];
    double price;
};

class BookCollection
{
    protected:
        books *x;
        int n;
    public:
        BookCollection(books *x1, int n1)
        {
            x = x1;
            n = n1;
        }
};

class NewBookCollection : public BookCollection
{
    protected:
        books *y;
    public:
        NewBookCollection(books *x1, int n1) : BookCollection(x1, n1)
        {
            y = new books [n];
            if (y == nullptr)
                exit (1);
        }

        void newcollection()
        {
            int max;
            max = x[0].price;
            for(int i = 1; i < n; i++)
            {
                if (max < x[i].price)
                    max = x[i].price;
            }

            for (int i = 0; i < n; i++)
            {
                strcpy(y[i].author, x[i].author);
                strcpy(y[i].title, x[i].title);
                
                if (x[i].price != max)
                    y[i].price = x[i].price;
                else
                    y[i].price = 0.8 * x[i].price;
            }
        }

        void print()
        {
            newcollection();
            for (int i = 0; i < n; i++)
            {
                cout << y[i].author << " " << y[i].title << " " << y[i].price << endl;                
            }
        }
        ~NewBookCollection()
        {
            delete []y;
            y = nullptr;
        }
    
};

int main()
{
    books xx[50];
    int nn;

    do
    {
        cout << "Grqeri qanak: ";
        cin >> nn;
    } while (nn < 2 || nn > 50);

    for(int i = 0; i < nn; i++)
    {
        cout << "Hexinaki anun: ";
        cin >> xx[i].author;
        cout << "Grqi vernagir: ";
        cin >> xx[i].title;
        cout << "Grqi giny: ";
        cin >> xx[i].price;
    }
    NewBookCollection Collection1(xx, nn);

    cout << "  Nor Cucak  " << endl;
    Collection1.print();
    return 0;
}