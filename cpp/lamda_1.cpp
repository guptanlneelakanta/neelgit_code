#include<iostream>
#include<functional>
#include<cmath>
using namespace std;

//lambda as function argument
void operate(int a, int b, function <int (int, int )>func)
{
cout<<func(a,b)<<endl;

}
int main()
{
    int a=5, b=6;

    auto x = [](int a, int b){ return a+b;};

    auto m = x(a,b);
    cout<<"m= "<< m<<endl;

    auto devide = [](double a, double b)->double {return a/b;};

    cout<<devide(33.4, 3.6)<<endl;

    //lambda with arguments + capture

    cout<<"\n ---1-----modify------ = "<<endl;

    int offset =10;
    auto sum = [offset](int a, int b){
        return a+b+offset;
    };
    cout<<sum(6, 8)<<endl;

    //lambda as function argument
    operate(4,6, [](int x, int y){ 
        return x+y; 
    });

    cout<<"\n ----2----modify------ = "<<endl;
    auto modify = [](int &x, int y){
        x  = x + y;
    };

    int k=5;
    modify(k, 10);
    cout<<"\n k = "<<k<<endl;

    //lambda with default arguments

    auto power = [](int base, int p=2){
        return pow(base, p);
    };

    cout<<"\n power = "<<power(5)<<endl;
    cout<<"\n power = "<< power(2, 4)<<endl;


    vector<pair<int,int>> v = {{1,4}, {2,1}, {3,2}};

    cout<<"\n before sort"<<endl;
        for(auto a : v)
        {    
              cout<< a.first <<" "<< a.second <<endl;
        }


    sort(v.begin(), v.end(),
     [](const pair<int,int>& a,
        const pair<int,int>& b) {
         return a.second < b.second;
     });

     cout<<"\n after sort"<<endl;
        for(auto a : v)
        {    
              cout<< a.first <<" "<< a.second <<endl;
        }


}