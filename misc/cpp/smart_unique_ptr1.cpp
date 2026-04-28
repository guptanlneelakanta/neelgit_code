#include<iostream>
#include <memory>
#include <string>

using namespace std;

class Uclass{
    private:
        unique_ptr <string> str1 ;

    public:
        Uclass(const string &s2) : str1(make_unique<string>(s2)){};
        void print() const
        {
          cout <<" uclass = "<<*str1 <<endl;
        }
};

class Address {
    public:
        std::string city;

        Address(const std::string& c) : city(c) {
            std::cout << "Address created\n";
        }

        ~Address() {
            std::cout << "Address destroyed\n";
        }
};

class Student {
    private:
        std::string name;
        std::unique_ptr<Address> address;  // exclusive ownership

    public:
        Student(const std::string& n, const std::string& city)
            : name(n), address(make_unique<Address>(city)) {}

        void print() const {
            std::cout << "Name: " << name
                    << ", City: " << address->city << std::endl;
        }
};

int main()
{
    unique_ptr <int> uptr1 = make_unique<int>(100);

    cout << "\n uptr1 value" << *uptr1 << endl;
    unique_ptr<int> ptr2 = move(uptr1);
    //unique_ptr<int> ptr3 = move(uptr1);
    //cout << "\n ptr3 value" << *ptr3 << endl;
    cout << "\n ptr2 value" << *ptr2 << endl;
   
    Student s("Ravi", "Bengaluru");
    s.print();
 
    Uclass uc("test1");
    uc.print();
    return 0;
}


