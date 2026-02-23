#include<iostream>

using namespace std;


class Animal{

    public:
        Animal() {}
        virtual void speak()
        {
            cout<<"animal sounding"<<endl;
        }
};

class Dog: public Animal{
public:
       void speak() override
        {
            cout<<"dog sounding"<<endl;
        }
};

int main()
{
    Animal *ani = new Animal();
    Dog *d = new Dog();

    ani->speak();
    d->speak();    
}

