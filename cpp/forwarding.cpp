#include <iostream>
using namespace std;

void process(int& x) {
    cout << "Lvalue version\n";
}

void process(int&& x) {
    cout << "Rvalue version\n";
}

template <typename T>
void wrapper(T arg) {
    process(arg);  // ❌ arg is always an lvalue
}

int main() {
    int a = 10;

    wrapper(a);    // expects lvalue
    wrapper(20);   // expects rvalue, but calls lvalue version
}
