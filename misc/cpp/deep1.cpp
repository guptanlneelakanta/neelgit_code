#include <iostream>
using namespace std;

class Deep {
public:
    int *data;

    Deep(int val) {
        data = new int(val);
    }

    // Deep copy constructor
    Deep(const Deep& other) {
        data = new int(*other.data);
    }

    ~Deep() {
        delete data;
    }
};

class deep2{

    public:
    int *data;

    deep2(int d){ 
        data = new int(d);
    }

    deep2(const deep2 &d2)
    { 
        data = new int(*d2.data);
    }
};

int main() {
    Deep a(20);
    Deep b = a;   // deep copy

    *b.data = 99;
    cout << *a.data << " " << *b.data << endl;    

    deep2 d1(33);
    deep2 e=d1;
    *e.data = 55;
    
    cout<< *d1.data<<"  "<< *e.data<<endl;

}
