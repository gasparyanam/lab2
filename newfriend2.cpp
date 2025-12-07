#include <iostream>

using namespace std;

struct comp
{
    int a;
    int b;
};

class c_comp
{
private:
    comp *p1;
    comp *p2;
    comp *x;
    int n;

public:
    c_comp(int n1)
    {
        n = n1;
        p1 = new comp[n];
        p2 = new comp[n];
        x = new comp[n];

        cout << "Nermuceq arajin comp tipi zangvats@ (a b):" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "A[" << i << "]: ";
            cin >> p1[i].a >> p1[i].b;
        }

        cout << "Nermuceq erkrord comp tipi zangvats@ (a b):" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "B[" << i << "]: ";
            cin >> p2[i].a >> p2[i].b;
        }
    }

    c_comp(const c_comp &ob1)
    {
        this->n = ob1.n;

        this->p1 = new comp[n];
        this->p2 = new comp[n];
        this->x = new comp[n];

        for (int i = 0; i < n; i++)
        {
            p1[i].a = ob1.p1[i].a; p1[i].b = ob1.p1[i].b;
            p2[i].a = ob1.p2[i].a; p2[i].b = ob1.p2[i].b;
            x[i].a = ob1.x[i].a;  x[i].b = ob1.x[i].b;
        }
    }

    ~c_comp()
    {
      delete []p1; 
      p1 = nullptr; 
      
      delete []p2; 
      p2 = nullptr;
      
      delete []x;
      x = nullptr;
      
      cout << "-> c_comp obyekt@ vochnchacvec" << endl;
    }

    void GUMARUM_METOD() 
    {
        for (int i = 0; i < n; i++)
        {
            x[i].a = p1[i].a + p2[i].a;
            x[i].b = p1[i].b + p2[i].b;
        }
    }
    
    void TPEL()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "(" << x[i].a << " + " << x[i].b << "i) ";
        }
        cout << endl;
    }
    
    friend void ARTADRJAL(c_comp&);
    friend void GUMAR(c_comp); 
};

void ARTADRJAL(c_comp &obb)
{
    for (int i = 0; i < obb.n; i++)
    {
        int real_part = obb.p1[i].a * obb.p2[i].a - obb.p1[i].b * obb.p2[i].b;
        int imag_part = obb.p1[i].a * obb.p2[i].b + obb.p1[i].b * obb.p2[i].a;
        
        obb.x[i].a = real_part;
        obb.x[i].b = imag_part;
    }
}

void GUMAR(c_comp ob)
{
    ob.GUMARUM_METOD();
    
    cout << "\n* Barekam funkcia GUMAR(ob) (Copy):" << endl;
    cout << "  x zangvats@ ob copy-i vra ";
    ob.TPEL();
}

int main()
{
    int n;
    
    do 
    { 
        cout << "Nermuceq zangvatsneri chap@ (n > 0): "; 
        cin >> n;
    } while (n <= 0);
    
    c_comp OB(n);

    cout << "\n--- 1. ARTADRJAL (Friend Function by Reference) ---" << endl;
    ARTADRJAL(OB);
    cout << "  OB.x zangvats@ ARTADRJAL-ic heto ";
    OB.TPEL(); 
    
    cout << "\n--- 2. GUMAR (Friend Function by Value) ---" << endl;
    GUMAR(OB);
    
    cout << "\n  OB.x zangvats@ GUMAR-ic heto (mnum e ARTADRJAL-i ardyunq@)՝ ";
    OB.TPEL(); 
    
    cout << "\n--- 3. GUMARUM_METOD (Public Method) ---" << endl;
    OB.GUMARUM_METOD();
    cout << "  OB.x zangvats@ GUMARUM_METOD-ic heto ";
    OB.TPEL();
    
    cout << "\nDas@ avartvec:" << endl;
    return 0; 
}