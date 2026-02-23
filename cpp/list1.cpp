#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    list<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    cout << "List elements: ";
    for (int n : myList){
        cout << n << " ";
    }
    cout << endl;

    auto it = myList.begin();

    advance(it , 2);
    myList.insert(it, 55);

    cout << "List elements: ";
    for (int n : myList){
        cout << n << " ";
    }
    cout << endl;

    cout<<myList.front()<<endl;
    cout<<myList.back()<<endl;

    myList.front() = 44;
    myList.back() = 74;
    
    cout << "List elements: ";
    for (int n : myList){
        cout << n << " ";
    }
    cout << endl;

    cout<< *next(myList.begin(), 2)<<endl;

    auto it2=myList.begin();
    advance(it2, 2);
    *it2 = 66;
    cout << "List elements: ";
    for (int n : myList){
        cout << n << " ";
    }

    auto it3 = find(myList.begin(), myList.end(), 74 );

    if(it3 != myList.end())
        cout<< *it3<<endl;
    else
        cout<< "it3 not found"<<endl;

    myList.erase(it3);

    for(auto i=myList.begin(); i!=myList.end(); i++ )
    cout<<*i<<endl;


    return 0;
}