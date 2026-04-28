#include<iostream>
using namespace std;

class Car{
    public:
    virtual void drive()=0;
    ~Car() { cout<<"car destructor is called."<<endl; }
};

class SUV : public Car
{
public:
    void drive()
    {       
            cout<<"drive suv car"<<endl;        
    }
};

class SEDAN : public Car
{
    public:
        void drive()
        {
            cout<<"drive sadan car"<<endl;        
        }
};

class Carfactory{
    public:
        virtual Car *createcar()=0;
        virtual  ~Carfactory(){}
        
};

class SuvCarfactory: public Carfactory{
    public:
    Car* createcar()
    {
      return new SUV;
    };
};

class SedanCarfactory: public Carfactory{

    public:
     Car*  createcar()
    {
      return new SEDAN;
    };
};

int main()
{
    Carfactory *factory = new SuvCarfactory();
    Car *car = factory->createcar();
    car->drive();
    delete car;
    delete factory;

    factory = new SedanCarfactory();
    car = factory->createcar();
    car->drive();
    delete car;
    delete factory;
    return 0;
}


