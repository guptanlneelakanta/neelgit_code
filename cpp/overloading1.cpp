#include<iostream>
using namespace std;

class Box{
    private:
        int length, breadth, height;

    public:
    Box(int l, int b, int h) : length(l), breadth(b), height(h){}
    Box() { length=2, breadth=3, height=4; }
        int add(int a, int b){return a+b;};
        float add(float a, float b){return a+b;};

        Box operator + (Box m)
        {
            Box box;
            box.length  = this->length + m.length;
            box.breadth  = this->breadth + m.breadth;
            box.height  = this->height + m.height;
            return box;
        }        

        int getvolume()
        {
            return length*breadth*height;
        }

};
 
int main()
{
    int m=3, m2=7, n;
    Box p;

    n=p.add(m,m2);
    float f,f1=22.3,f2=44.4;
    f=p.add(f1, f2);
    cout<<n<<endl;
    cout<<f<<endl;

    Box b1(3, 6, 8);
    Box b2(3, 6, 8);

    Box b3;
    b3=b1+b2;
    int volume = b3.getvolume();
    cout<<"\n volume = "<<volume<<endl;
}

