#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int k=78;
    auto f=[=, &k](){return a+34+k;};

    auto m = f();
    cout<< m << endl;

    
}


