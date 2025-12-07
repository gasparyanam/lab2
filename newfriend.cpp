#include <iostream>
using namespace std;

struct comp
{
	int a;
    int b;
};
//-------------    das@ ----------------------
class c_comp
{
    private:
        comp *p1;
        comp *p2;
        comp x[30];
        int n;
    public:
//-----------------------    constructor    ------------
	c_comp(int n1 )
	{
        cout << "Starting constructor" << endl;
		n=n1;
        p1 = new comp[n];
	    p2 = new comp[n];

	    cout<< "nermutseq arajin comp tipi zangvats@."<<endl;
        for(int i=0;i<n;i++) 
            cin>>p1[i].a>>p1[i].b;

	    cout<< "nermutseq erkrord comp tipi zangvats@."<<endl;
        for(int i=0;i<n;i++)
            cin>>p2[i].a>>p2[i].b;
	}

// -------------- copy constructor ------------------------------
    c_comp(const c_comp &ob1)
	{
        cout << "Copy Constructor" << endl;
	    n = ob1.n ;
	    p1 = new comp[n];
	    p2 = new comp[n];
	    for (int i=0 ;i<n;i++) 
        {
            p1[i] = ob1.p1[i];
            p2[i] = ob1.p2[i];
        }
	}
// -------------- destuctor ------------------------------

	~c_comp()
    {
      delete []p1; p1=0;
      delete []p2; p2=0;
      cout<<"~c_comp"<<endl;
    } 
    void TPEL() 
    {     
        for(int i=0;i<n;i++)
            cout<<x[i].a<<"  "<<x[i].b<<endl;    
    }
// -------f-eri barekamutian hastatum@ -------------
            friend  void  ARTADRJAL(c_comp&);
	        friend  void  GUMAR(c_comp);
	} ;
//------------------- dasi verj@ -------------
int main()
{
    int  n;
    do 
    { 
        cout<<"n = "; 
        cin >>n;
    } while(n < 2 || n > 30);
    c_comp  OB(n) ;     // himnakan construktor
    ARTADRJAL (OB); 
    cout << "himn. ob-i x zangvats@ artadrjalic" << endl;
	OB.TPEL();  
    GUMAR (OB);
    cout << "himn. ob-i x zangvats@- artadrjalic nujnn e" << endl; 
    OB.TPEL (); 
    return (0); 
}
   //----------------    1-in friend f-a   --------------------
void  ARTADRJAL (c_comp &obb) 
{
    for( int  i=0; i<obb.n; i++) 
    {
        obb.x[i].a=obb.p1[i].a*obb.p2[i].a;
        obb.x[i].b= obb.p1[i].b*obb.p2[i].b;
    }
}
   
//---------- 2-rd friend f-a---------------------
void GUMAR (c_comp ob)
{ 
	for(int i=0;i<ob.n; i++) 
    {
        ob.x[i].a = ob.p1[i].a+ob.p2[i].a;
        ob.x[i].b = ob.p1[i].b+ob.p2[i].b;
    }
    cout<<"copy ob-i mej 1+2 zangvatsneri gumarn e stacvel x-um"<<endl;
    ob.TPEL();
} 