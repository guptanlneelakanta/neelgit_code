
#include<iostream>
#include<vector>

using namespace std;

class pair_test{

    public:
pair<int, string>  fun(pair<int, string> v1);    
};

pair<int, string> pair_test::fun(pair<int, string> p1)
{
return p1;
}


int main()
{
    pair<int, string> p2 = {33, "test1"};
    cout<<"\nhello == ";
    pair_test p_cls;

    pair <int, string >v3 = p_cls.fun(p2);
    cout<<"max = "<<v3.first<<"  "<< v3.second <<endl;
    
}