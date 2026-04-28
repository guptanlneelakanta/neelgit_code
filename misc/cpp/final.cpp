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

   void display ()
   {
    cout<<"\n display"<<endl;
   }
};

class Mammal : public Animal {
   public:
   void makeSound() override{
      cout << "Mammal sound" << endl;
   }

   // final function
   //void breathe() final override {
    void breathe() override {
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

   Animal an;
   an.display();
   return 0;
}