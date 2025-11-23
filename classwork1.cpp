#include <iostream>
using namespace std;

struct book
{
    char author[20];
    char title[20];
    double price;
};

class BookCollection
{
    protected:
        int n;
        book *x;
    public:
        BookCollection(book *x1, int n1)
        {
            x = x1;
            n = n1;
        }
};

class DiscountList : public BookCollection 
{
    public:
        DiscountList(book *x1, int n1) : BookCollection(x1, n1) {}

        void ex_price()
        {
            if (n <= 0) return;
            double maxprice = x[0].price;
            for (int i = 1; i < n; i++)
            {
                if (x[i].price > maxprice)
                    maxprice = x[i].price;
            }
            for (int i = 0; i < n; i++)
            {
                if (x[i].price == maxprice)
                    x[i].price *= 0.8;
            }
        }

        void print()
        {
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". " << x[i].author << " - " << x[i].title << " :" << x[i].price << endl;
            }
        } 
};

int main()
{
    int n_1;
    book x[20];
    do
    {
        cout << "n = ";
        cin >> n_1;
    } while (n_1 < 2 || n_1 > 20);

    for (int i = 0; i < n_1; i++)
    {
        cout << "Author name: ";
        cin >> x[i].author;
        cout << "Title: ";
        cin >> x[i].title;
        cout << "Price: ";
        cin >> x[i].price;
    }
    DiscountList ob(x, n_1);

    cout << "\nOriginal list:\n";
    ob.print();

    ob.ex_price();

    cout << "Modified list (20 percent off most expensive):";
    ob.print();

    return 0;
}
