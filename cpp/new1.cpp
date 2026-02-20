#include<iostream>
#include <memory>
using namespace std;

class Box{
    public:
Box(){
    cout<<"\n constructor is called"<<endl;
    }
~Box(){
    cout<<"\n destructor is called"<<endl;
    }
};

int main()
{
    Box *barray = new Box[4];
    int *p = new int(100);
    *p=434;
    *(p+1)=46;
    cout<<*p<<endl;
    cout<<*(p+1)<<endl;

    delete [] barray;
    delete [] p;
}

