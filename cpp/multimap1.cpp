#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Creating an empty multimap
    multimap<int, string> mm1;
    
    // Creating multimap using initializer list
    multimap<int, string> mm2 = {{1, "Geeks"},
                      {2, "For"}, {1, "C++"}};

    for (auto i : mm2)
        cout << i.first << ": " << i.second
        << endl;
    return 0;
}