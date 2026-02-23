// Implementation of Singleton Class 
// in C++
#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    // Member variables
    string name, loves;

    // Static pointer to the Singleton instance
    static Singleton* instancePtr;

    // Mutex to ensure thread safety
    static mutex mtx;

    // Private Constructor
    Singleton() {}

public:
    // Deleting the copy constructor to prevent copies
    Singleton(const Singleton& obj) = delete;

    // Static method to get the Singleton instance
    static Singleton* getInstance() {
        if (instancePtr == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instancePtr == nullptr) {
                instancePtr = new Singleton();
            }
        }
        return instancePtr;
    }

    // Method to set values
    void setValues(const string& name, const string& loves) {
        this->name = name;
        this->loves = loves;
    }

    // Method to print values
    void print() const {
        cout << name << " Loves " << loves << "." << endl;
    }
};
// int test1;
class simp1{
    public:
    static int test1;
    void test()
    {
        cout<<"test fun"<<endl;
    }
};

// Initialize static members
Singleton* Singleton::instancePtr = nullptr;
mutex Singleton::mtx;

// Driver code
int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->setValues("Manish", "GeeksForGeeks");
    s1->print();

    Singleton* s2 = Singleton::getInstance();
    s2->setValues("Vartika", "GeeksForGeeks");
    s2->print();
    
    cout<<s1<<endl;
    cout<<s2<<endl;
simp1::test1=323;
    return 0;
}