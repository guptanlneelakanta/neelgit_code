
#include<iostream>
using namespace std;

class Singleton{

private:
	 static Singleton *instance;
	 Singleton() {} // private constructor

public:
	static Singleton* getInstance()
	{
	if (instance == nullptr )
	instance = new Singleton();
        return instance;
    }
    
    void printfun()
    {
    cout<<"test1"<<endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();
    
    obj2->printfun();
    obj1->printfun();
    // Both point to the same instance
}
