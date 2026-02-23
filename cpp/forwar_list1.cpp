//#include<forward_list>
#include<bits/stdc++.h>

using namespace std;

void printFL(forward_list<int> &fl2)
{
    //for(auto i=fl2.begin(); i<fl2.end(); i++ )
    for(auto it : fl2)
    cout<<it <<" ";
}

int main()
{

forward_list<int> fl1 = {44,5,6,7,8};


printFL(fl1);
}