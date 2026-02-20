#include<iostream>
#include <memory>
using namespace std;

class Line{

    int *ptr;
public:
    Line() {};
    Line(int len){
    cout<<"constructor called = "<<len<<endl;
    ptr= new int;
    *ptr=len;
    }

    Line (const Line &obj) //copy constructor
    {
        cout<<" \n copy constructor called ."<<endl;
        ptr= new int ;
        *ptr= *obj.ptr;
    }
    
    int getlength();
};

void display(Line &obj)
{
    cout<<"\n obj.ptr = "<< obj.getlength()<<endl;
}

int Line::getlength()
{
    return *ptr;
}

int main()
{
    Line line(5) ;
    display(line);
    Line line2=line;
    display(line2);
}
