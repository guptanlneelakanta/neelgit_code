#include<iostream>
#include <string>
using namespace std;

class Shape{
    private:
        int *ptr;

    public:
        Shape(int l, int b, int p) : len(l), breadth(b){ 
            ptr=new int;
            *ptr=p;
        }

        Shape(int l, int b) : len(l), breadth(b){ }
        Shape(class Shape &obj) { 
            len= obj.len;
            breadth= obj.breadth;
        }
        
        virtual ~Shape()
        { 
            cout<<"base destructor is called"<<endl; 
        }

        virtual void area(){
            cout<<"\n this is an area in base class = "<< len*breadth<<endl;
        }
       
    protected:
        int len, breadth;
};


class triangle: public Shape{
    public:
    triangle(int l, int b) : Shape(l, b){};
    ~triangle() { cout<<"triangle destructor is called"<<endl;}
        void area()
        {
            int ar=len*breadth/2;
            cout<<"\n this is an area in triangle class = "<< ar<<endl;
        }
};

class rectangle: public Shape{
    
    public:
        rectangle(int l, int b) : Shape(l, b){};
        ~rectangle() { cout<<"triangle destructor is called"<<endl;}
        void area();
        
};


void rectangle ::area()
{
    int ar=len*breadth/2;

    cout<<"\n this is an area in rectangle class = "<< ar<<endl;            
}

int main()
{
    Shape *t= new triangle(4,5);
    t->area();
    Shape *t2= new rectangle(5,6);
    t2->area();

    Shape *t3=t2;
    t3->area();

    Shape *t4= new Shape(5,6,7);

    delete t;
    delete t2;
}