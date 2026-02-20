#include <iostream>
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
   void breathe() override { 
      cout << "Dog breathing" << endl;
   }
};

int main(){
   Dog dog;
   dog.makeSound(); 
   dog.breathe();   
   return 0;
}