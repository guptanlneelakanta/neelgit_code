#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    // Declares an empty vector
    vector<int> v1={3,4,5,6,7,8};
    
    // Declares vector with given size
    // and fills it with a value
    vector<int> v2(3, 5);  
    
    // Print items of v2
    for (int x : v2) {
        cout << x << " ";
    }
    cout<<"\n --v1---------";
    for (int x=0; x<v1.size(); x++) {
        cout << v1[x] << " ";
    }


    cout << endl;
    // Initializes vector using 
    // initializer list.
    vector<int> v3 = {1, 2, 3};  
    
    // Print items of v3
    for (int x : v3) {
        cout << x << " ";
    }
    
    v3.push_back(6);
       cout << endl;
    for (int x : v3) {
        cout << x << " ";
    }

    cout << endl;
    v3.pop_back();

    for (int x : v3) {
        cout << x << " ";
    }

    cout << endl;
    v3.insert(v3.begin()+2, 45 );
cout<<"\n v3---1"<<endl;
    for (int x : v3) {
        cout << x << " ";
    }
    cout<<"\n v3---2"<<endl;
    v3.erase(find(v3.begin(), v3.end(), 45));
    for (int x : v3) {
        cout << x << " ";
    }

    auto it = find(v3.begin(), v3.end(), 45);
    cout<<"\n it = "<<&it<<endl;
    cout<<"\n it = "<<*it<<endl;
    
    vector<int>v4;
    if(v4.empty())
    cout<<"\n v4 is empty"<<endl;

    v4.push_back(45);
    if(!v4.empty())
    cout<<"\n v4 is not empty"<<endl;

    cout<<showbase<<hex<<v4.max_size()<<endl;
    return 0;
}
