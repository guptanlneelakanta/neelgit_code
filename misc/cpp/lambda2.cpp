#include<iostream>
#include<vector>
#include<algorithm>

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

    auto resref = [&] (int m)
    {
            v1.push_back(m);
            v2.push_back(m);
        
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

    resref(30);
    resval(44);
    resmix(33);
    print(v1);
    print(v2);

    auto it = find_if(v1.begin(), v1.end(), [](int & a){ return (a%3==0) ;});
    cout<<"\n  it = "<< *it << endl;

}