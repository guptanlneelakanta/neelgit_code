#include <iostream>
#include <string>
using namespace std;

class Car{
    public:
    virtual void drive()=0;
    virtual ~Car(){}
};

class Suv:public Car{

    public:
    void drive(){
        cout<<"drive suv car"<<endl;
    }
};

class Sadan:public Car{
    public:
    void drive(){
        cout<<"drive sadan car"<<endl;
    }
};

class Carfactory{
    public:
        virtual Car* createcar()=0;
        virtual ~Carfactory(){}
};

class SuvFactory: public Carfactory{
    public:
    Car* createcar(){
        return new Suv();
    }
};

class SadanFactory:public Carfactory{
    public:
    Car* createcar(){
        return new Sadan();
    }
};


int main()
{
    Carfactory *factory = new SuvFactory();
    Car *scar = factory->createcar();
    scar->drive();

    delete factory;
    delete scar;

    factory = new SadanFactory();
    scar = factory->createcar();
    scar->drive();

    delete factory;
    delete scar;
}

