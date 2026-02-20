
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class vectortest{

public:
    int fun(vector<int> v1);    
};

int vectortest::fun(vector<int> v1)
{
    int max=0;
    for(int i : v1)
    if(i>max)
    max=i;
return max;
}


int main()
{
    vector<int> v2 = {33,4,55,6,77};
    cout<<"\nhello";
    vectortest v_cls;

    int v3 = v_cls.fun(v2);
    cout<<"max = "<<v3<<endl;

    v2.erase(find(v2.begin(), v2.end(), 55));

    for(auto i: v2)
        cout<<"\n v2 = "<<i <<"  ";

    if(v2.empty())
        cout<<"v2 is empty"<<endl;

    if(!v2.empty())
        cout<<"v2 is not empty"<<endl;

    vector<vector<int>> v4 = { {2,3,4}, {5,6,7}, {89,99, 6}};

    for(int i=0; i<v4.size(); i++)
    {
    for(int j=0; j<v4.size(); j++)
    {
         cout<<v4[i][j] << " ";      
    }
       cout<<endl;
    }
    vector<vector<int>> m(5, vector<int>(2, 0));

    for(int i=0; i<m.size(); i++)
    {
        for(int j=0; j<m.size(); j++)
        {
            cout<<m[i][j] << " ";
        }
        cout<<endl;
    }

}