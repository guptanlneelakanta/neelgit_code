#include<iostream>

using namespace std;

class Shape{

    protected:
        int length, bredth;

    public:
        Shape(int l, int b): length(l), bredth(b){};
        virtual int area(){
            cout<<"\n parent class area = "<< length*bredth <<endl;
            return length*bredth; }
};

class Triangle: public Shape{

    public:
    Triangle(int l=0, int b=0):Shape( l,  b){};
        int area(){
            cout<<"\n Trianlge class area = "<< length*bredth <<endl;
            return length*bredth; }
};

class Rectangle:public Shape{

    public:
    Rectangle(int l=0, int b=0):Shape( l,  b){};
        int area(){
            cout<<"\n Rectangle class area = "<< length*bredth <<endl;
            return length*bredth; }
    };

int main()
{
    Shape *s = new Shape(4,5);
    s->area(); 
    Triangle t(4,5);
    Rectangle r(8,9);
    s=&t;
    s->area();
    s=&r;
    s->area();
}