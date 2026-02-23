#include<iostream>

using namespace std;


class Shape{

    public:
        Shape(int l=0, int b=0) : length(l), breadth(b){}
        void setwidth();
        void getwidth(int length);
        void getlength(int length);
        virtual int area()=0;

//        int area(){ return length*breadth;};

    protected:
        int length, breadth;
};

class Rectangle: public Shape{
public:
Rectangle(int l=0, int b=0) : Shape(l,b){}
    int area()
    {
         return length*breadth;
    }
};

class Triangle: public Shape{
public:
Triangle(int l=0, int b=0) : Shape(l,b){}
    int area()
    {
        return length*breadth/2;
    }
};

int main()
{
    Triangle tri(5,4);
    Rectangle rec(5,4);

    Shape *sh= & tri;
    int ar = sh->area();

    cout<<"\n tri area = "<<ar<<endl;
    sh=&rec;
    ar = sh->area();
    cout<<"\n rec area = "<<ar<<endl;
}

