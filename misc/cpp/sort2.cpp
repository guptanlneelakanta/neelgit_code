#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);   // ascending order

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


     vector<vector<int>> v = {
        {3, 4},
        {1, 2},
        {5, 0}
    };

    sort(v.begin(), v.end());

    for (auto &row : v) {
        cout << row[0] << " " << row[1] << endl;
    }

    return 0;
}
