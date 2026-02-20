#include<iostream>

using namespace std;

void fun(int &x)
{
    cout<<"\n x = "<<x<<endl;
    x++;
   
}

int main()
{

    int x=10;
fun(x);
 cout<<"\n xxxx = "<<x<<endl;
}