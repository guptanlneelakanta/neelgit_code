#include<iostream>
#include<memory>
using namespace std;


class Shape{
    
    private:
        int l, b;

    public:
        Shape( int len, int bred ): l(len), b(bred){}
        
        virtual void disp(){
            cout<<"\n this is a shape class area = "<< this->area()<<endl;
        }

       virtual int area(){
            cout<<"\n this is an area in base class = "<< l*b<<endl;
            return l*b;
        }

        ~Shape(){
            cout<<"base destructor is called"<<endl;
        }        
};

class Triangle:public Shape{

    
    public:
        Triangle( int len, int bred): Shape(len, bred){};
        int area(){
            int ar=Shape::area()/2;
            cout<<"\n this is an area in triangle class = "<< ar<<endl;
            return ar;
        }

        ~Triangle(){
            cout<<"triangle destructor is called"<<endl;
        }
};


int main()
{
    Shape *obj;
    Triangle tri(3,5);
    obj=&tri;
    obj->Shape::disp();
    obj->area();

    unique_ptr<int> ptr1 = make_unique<int>(122);

    cout<<"\n value of ptr1 = "<<*ptr1<<endl;
    unique_ptr<int> ptr2 = move(ptr1);

    cout<<"\n value of ptr2 = "<<*ptr2<<endl;

    
    return 0;
}

