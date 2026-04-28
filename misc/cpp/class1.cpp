#include<iostream>
#include <memory>
#include <string>

using namespace std;

class Box
{
    public:
        Box(int l, int b, int h ):len(l), breadth(b), height(h){
              cout<<"\n constructor is called"<<endl;
        }
      //  Box(const Box &b);

        //deep copy
        Box(const Box &b2){
            cout<<"\ndeep copy constructor is called"<<endl;
            data=new int (*b2.data);
             len=b2.len;
    breadth=b2.breadth;
    height = b2.height;    
        }
        ~Box();
        int volume(void);

    private:
        int len, breadth, height;
        int *data;
};

Box::~Box()
{
    cout<<"\n destructor is called"<<endl;
}
/*
Box::Box(const Box &b)
{
    cout<<"\n copy constructor is called"<<endl;
    len=b.len;
    breadth=b.breadth;
    height = b.height;    
}
*/
int Box :: volume(void)
{
    return len*breadth*height;
}

int main()
{
    Box Box1(3,4,6);
    Box *Box2 =new Box(3,4,6);
    cout<<Box2->volume()<<endl;

    Box Box3(Box1);    
    cout<<"\n box3 = "<<Box3.volume()<<endl;

    
    Box Box5=Box1;
    cout<<"\n box4 = "<<Box5.volume()<<endl;

}