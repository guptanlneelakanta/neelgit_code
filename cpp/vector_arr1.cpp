#include<iostream>
#include<vector>

using namespace std;

void printarr(vector<int> stdvector)
{
    cout<<"\n vector.size= "<< stdvector.size()<<endl;
    for(auto i : stdvector)
    cout<<i<<" ";
}

int main()
{
    vector<int> stdvec={3,5,66,7,8};
    printarr(stdvec);

    int *p=new int();
    *p=34;
    cout<<"\n *p = "<<*p<<endl;
    delete p;
    *p=343;
    cout<<"\n *p = "<<*p<<endl;
    *p=3444;
    cout<<"\n *p = "<<*p<<endl;

    *(p+1)=3444;
    cout<<"\n *p = "<<*(p+1)<<endl;
}


