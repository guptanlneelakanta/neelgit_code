#include <iostream>
using namespace std;
extern int add(int a, int b);

int main()
{
    int res = add(4,5);
    cout<<"\n res = "<<res<<endl;
    return 0;
}

