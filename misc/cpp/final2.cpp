#include<iostream>
using namespace std;

class base final{

    public:
    void print()
    {
        cout<<"\n hello world"<<endl;
    }
};

/*
class derived:public base{
public:
void print2()
{
    cout<<"\n print2"<<endl;
}
};
*/

int main()
{
base d;
d.print();

}