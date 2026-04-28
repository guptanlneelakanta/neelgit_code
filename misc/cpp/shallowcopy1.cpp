#include<iostream>
using namespace std;


class shallowcopy{
    private:
        int *m;

    public:
    shallowcopy(int y){
        m = new int (y);
    }

    ~shallowcopy()
    {
        cout<<"\n destructor is called"<<endl;
        //delete m;
    }

    void print()
    {
        cout<<"--^x = "<< m<<"=== "<<*m<<endl;
    }
};

class deepcopy{
    private:
    int *x;
    public:
    deepcopy(int y){ x=new int(y);}

    deepcopy(const deepcopy &y){ x = new int(*y.x); }
    ~deepcopy()   {
        cout<<"\n destructor is called"<<endl;
        delete x;
    }

    void print()
    {
        cout<<"--^x = "<<x<<"=== "<<*x<<endl;
    }
};

int main()
{
    shallowcopy s1(10);
    shallowcopy s2 =s1;

    s1.print();
    s2.print();

    deepcopy d1(20) ;
    deepcopy d2 =d1;

    d1.print();
    d2.print();
}