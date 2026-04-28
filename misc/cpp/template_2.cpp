#include<iostream>
#include <memory>
using namespace std;

template <typename T>
T const&  Max(T const& a, T const& b){
    return (a>b)? a:b;
}

int main()
{
    int a=4, b=6;
    int m= Max(a,b);

    cout<<"\n max = "<<m<<endl;

     float c=4.6, d=8.6;
    float n= Max(c,d);

    cout<<"\n max = "<< n<<endl;

    string s1="hello", s2="welcome";
    string s3= Max(s1,s2);

    cout<<"\n max = "<< s3<<endl;
}
