#include<iostream>
using namespace std;

template <typename T>
T add (T a, T b)
{
    return a+b;
}


int main()
{

    int m =add<int>(5,6);

    cout<<m<<endl;

}
