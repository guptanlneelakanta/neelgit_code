
#include<iostream>
#include<array>

using namespace std;

void printarr(array<int, 5> arr)
{
    for(auto i : arr)
    cout<<i <<" ";

}

int main()
{
    array<int , 5> stdarr ={33,4,5,6,7};

    printarr(stdarr);

}