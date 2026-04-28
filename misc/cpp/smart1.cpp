#include <iostream>
using namespace std;

int main(){   
    int *ptr1 = new int(42);    // allocating memory
    cout << "ptr1 pointer Value: " << *ptr1 << endl;
    // Here memory leak occurs as we have
    // not freed the allocated memory

    int *ptr2 = new int(100);   // allocating memory
    cout << "ptr2 pointer value: " << *ptr2 << endl; // dangling pointer
    delete ptr2;                // clearing the memory
    // accessing freed memory
   // cout << "ptr2 pointer value: " << *ptr2 << endl; // dangling pointer
    delete ptr1;
    return 0;
}



