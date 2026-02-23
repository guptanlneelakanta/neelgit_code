#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms = {5, 3, 3, 1};

    // Finding an element (3)
    auto it = ms.find(3);

    if (it != ms.end())
        cout << *it<<endl;
    else
        cout << "Not Found!";

        for(auto i : ms)
        cout << i <<" ";

        auto it2 = ms.find(1);
    cout<<"it2 = "<<*it2<<endl;

    return 0;
}

