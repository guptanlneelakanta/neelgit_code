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
        cout<<"\n derived class x = "<<endl;
	cout<<"\n x = "<<x<<endl;
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

int main()
{
	Base *b = new Base;
	Derived d;
	b=&d;
	b->display(22.4);
//    delete b;

    int f = d.recursive_fact(14);
    cout<<"\n fact="<<f<<endl;
}




