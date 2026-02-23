#include <bits/stdc++.h>
using namespace std;

struct Compare
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    vector<int> v={3,2,65,34,98,45};
    sort(v.begin(), v.end(), Compare()); // Custom sorting
    for(int i:v) cout<<i<<" ";
    return 0;
}