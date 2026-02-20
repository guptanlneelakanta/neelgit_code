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

namespace first_namespace{

    void func()
    {
        cout<<"func first namespace is called."<<endl;
    }
}

namespace second_namespace{

    void func()
    {
        cout<<"func second namespace is called."<<endl;
    }
}

using namespace first_namespace;
int main()
{
    func();
    second_namespace::func();
}

