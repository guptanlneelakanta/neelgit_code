#include <iostream>
#include <iomanip>

using namespace std;

class Animal {
   public:
   virtual void makeSound(){
      cout << "Animal sound" << endl;
   }

   virtual void breathe(){
      cout << "Animal breathing" << endl;
   }
};

class Mammal : public Animal {
   public:
   void makeSound() override{
      cout << "Mammal sound" << endl;
   }

   // final function
   void breathe() final override {
      cout << "Mammal breathing" << endl;
   }
};

class Dog : public Mammal{
   public:
   void makeSound() override {
      cout << "Bark" << endl;
   }

   // This would cause an error
   void brea2the() { 
      cout << "Dog breathing" << endl;
   }
};

int main(){
   Dog dog;
   dog.makeSound(); 
   dog.breathe();   

   int num =323;
   cout<<"\n Left alig : "<<left<<setw(5)<<num<<endl;
   cout<<"\n Right alig : "<<right<<setw(5)<<num<<endl;
   return 0;
}