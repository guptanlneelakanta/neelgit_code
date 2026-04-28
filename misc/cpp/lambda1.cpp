#include<iostream>
#include<vector>
using namespace std;

void print(vector <int> v1)
{
    for(auto i :v1)
    cout<<"v1 : "<< i <<endl;

}

int main()
{ 
    auto res = [&] (int a, int b)->int { return a+b; };
    cout<<res(3,4)<<endl;

    vector <int > v1, v2;

    auto resref = [&] ()
    {
        for(int i=0; i<5; i++)
        {
            v1.push_back(i);
            v2.push_back(i);
        }
    };

    auto resval = [=] (int m) mutable
    {        
            v1.push_back(m);
            v2.push_back(m);        
    };

    auto resmix = [&v1, v2] (int m) mutable
    {        
            v1.push_back(m);
            v2.push_back(m);        
    };

    resref();

      resval(44);
   resmix(55);
    print(v1);
    print(v2);

}