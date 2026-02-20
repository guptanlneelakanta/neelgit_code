#include<iostream>
#include <memory>
using namespace std;

class Box
{
double width;

public:
friend void printwidth(Box b)
{
cout<<"\n width = " << b.width <<endl;
}
void setwidth(double w);

};

void Box::setwidth(double w)
{
width=w;
}
/*void printwidth(Box b)
{
cout<<"\n width = " << b.width <<endl;
}
*/
int main()
{

Box b1;
b1.setwidth(3.5);
printwidth(b1);

}
