// C++ Program to check if an element exists in
// in an set using std::binary_search()
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {1, 4, 5, 7, 9};
    int k = 8;

    // Check if the element exists
    if (binary_search(s.begin(), s.end(), k))
        cout << k << " is Present";
    else
        cout << k << " is NOT Present";
    return 0;
}