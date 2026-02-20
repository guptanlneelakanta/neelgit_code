#include<iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}        // destructor CAN be virtual
    virtual Base* create() = 0;  // acts like virtual constructor
    virtual void print()=0;
};

class Derived : public Base {
public:
    Base* create() override {
        cout<<"virtual cons"<<endl;
        return new Derived();
    }

    void print()
    {
        cout<<"\n test fun"<<endl;
    }
};


int main()
{
    Base* obj = new Derived();
    Base* obj2 = obj->create();   // runtime object creation

   obj2->print();
}

