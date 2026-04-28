#include<iostream>
using namespace std;

class Base {
public:
    virtual void display(int x){    cout<<"\n base class x = "<<x<<endl;};
};

class Derived : public Base {
public:
   void display(int  x) override
    {
        cout<<"\n derived class x = "<<x<<endl;	    
    }

    int recursive_fact(int n);
};

int Derived:: recursive_fact(int n)
{
    int fact=n;
    if(n==1)
        return fact;
    fact=fact*recursive_fact(n-1);
}

class derived2 : public Base{

    public:
        void display(int m) override
        {
             cout<<"\n derived2 class = " <<m<<endl;
        }
};

int main()
{
	Base *b = new Base;
    b->display(44);
	Derived d;
	b=&d;
	b->display(22.4);

    derived2 d2;
	b=&d2;
	b->display(22.4);
//    delete b;

    int f = d.recursive_fact(14);
    cout<<"\n fact="<<f<<endl;
}




