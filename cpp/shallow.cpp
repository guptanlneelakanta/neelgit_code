#include <iostream>
using namespace std;

class Shallow {
public:
    int *data;

    Shallow(int val) {
        data = new int(val);
    }

    // default copy constructor → SHALLOW COPY
    ~Shallow() {
        delete data;
    }

    void setdata(int d)
    {
        *data =d;
    }
};

int main() {
    Shallow a(10);
    Shallow b = a;   // shallow copy
    
    *b.data = 32;
    cout << *a.data << " " << *b.data << endl;

}
