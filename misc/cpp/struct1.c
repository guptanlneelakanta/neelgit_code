#include <stdio.h>


struct MyStruct {
    int x;            // public by default
    void show() {
        cout << "Struct x = " << x << endl;
    }
};

int main() {
    struct MyStruct s; 
    s.x = 10;      // allowed (public by default)
    s.show();

   
}