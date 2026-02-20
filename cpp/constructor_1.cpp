#include<iostream>
using namespace std;

class Test1{

    string name;
    int age; 
    int id;

    public:
        Test1(const string & name1, int age1, int id1) : name(name1), age(age1), id(id1){}
        Test1(const string & name1 ): Test1(name1, 18, 32){}
        ~Test1(){
             cout<<"destructor called"<<endl;
             }
        void display()
        {
            cout<<"\n name = "<<name<<endl;
            cout<<"\n age = "<<age<<endl;
            cout<<"\n id = "<<id<<endl;
        }

};

class Base{

    public: 
    Base(){
        cout<<"\n base constructor is called"<<endl;
    }

    ~Base(){
        cout<<"\n base destructor is called"<<endl;
    }

    virtual void disp(){
        cout<<"\n base class is called"<<endl;
    }
};

class Derived : public Base{
    public:

    Derived(){
        cout<<"\n Derived constructor is called"<<endl;
    }
      ~Derived(){
        cout<<"\n Derived destructor is called"<<endl;
    }

        void disp()
        {
            cout<<"\n derived class is called"<<endl;
        }
};

int main()
{
    const string &name ="name1";
    Test1 t(name, 34, 12);
    t.display();
    const string &name2 ="bane11";
    Test1 t1(name2);
    t1.display();

    Test1 *t3 = new Test1(name2, 33,4);
    t3->display();
    delete t3;

    Base *b1 = new Derived;
    b1->disp();

    delete b1;
}

