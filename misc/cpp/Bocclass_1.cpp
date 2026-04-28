#include<iostream>

using namespace std;

class Box{

    public:
        Box(double l, double b, double h): length(l), bredth(b), height(h){  objectcount++;};
        Box(){  objectcount++;};
        Box(Box &x): length(x.length), bredth(x.bredth), height(x.height){  objectcount++;};

        static int objectcount;


        double volume()
        {
            return length * bredth * height;
        }

        static int getobjectcount()
        {
            return objectcount;
        }
        friend void testprint(Box x);
        
        int compare(Box b);
        Box operator + (const Box x);
        void operator = (const Box x);
        Box operator - ();

        bool operator < (const Box x);

        friend ostream& operator<<(ostream &output , const Box & x)
        {
            output<<"x.length = "<<x.length<<endl;
            output<<"x.bredth = "<<x.bredth<<endl;
            output<<"x.height = "<<x.height<<endl;
return output;
        }

    private :
        double length;
        double bredth;
        double height;
};

void Box::operator= (const Box x)
{
    length= x.length;
    bredth= x.bredth;
    height= x.height;    
}

Box Box::operator + (const Box x)
{
    Box y;
    y.length=this->length + x.length;
    y.bredth=this->bredth + x.bredth;
    y.height=this->height + x.height;
    return y;
}

bool Box::operator < ( Box x)
{
    bool y;
    y=this->volume() < x.volume();
    
    return y;
}

Box Box::operator - ()
{
    length =-length;
    bredth =-bredth ;
    height =-height ;
    return Box(length, bredth, height);
}

void testprint(Box x)
{
    cout<<"\n testfun"<<endl;
    cout<<"\n x.length = "<<x.length  <<endl;
    cout<<"\n x.bredth = "<<x.bredth  <<endl;
    cout<<"\n x.height = "<<x.height  <<endl;            
}


int Box:: compare(Box b)
{
    return this->volume() > b.volume();
}

int Box::objectcount =0;

int main()
{  
    Box b1(4.5, 6.7, 8.9);
    Box b2(7, 6, 8.9);
    Box b3(7, 6.5, 12);

    Box b4=b3;
    Box b5;
    double v4 = b4.volume();
    cout<<"\n v4 = "<<v4<<endl;
    double v3 = b3.volume();
    cout<<"\n v3 = "<<v3<<endl;
    b3=b1+b2;

    testprint(b1);
    double v = b1.volume();
    double v2 = b2.volume();
    v3 = b3.volume();
    cout<<"\n v = "<<v<<endl;

    cout<<"\n v2 = "<<v2<<endl;
    cout<<"\n v3 = "<<v3<<endl;
    
    int cnt = Box::getobjectcount();
    cout<<"\n cnt = "<< cnt <<endl;

    int comp = b2.compare(b1);
    cout<<"\n comp = "<<comp<<endl;
    b3=-b3;
    testprint(b3);

    bool m = b1<b2;
    cout<< "\n m = "<<m<<endl;
    cout<< b4;
    b4=b1;
    cout<<"b1 = "<< b1;
    cout<<"b4 = "<< b4;
}

