#include <iostream>
#include <string>
using namespace std;
// Product interface
class Pizza {
   public:
      virtual string getType() = 0;
};
// Concrete Products
class Margherita : public Pizza {
   public:
      string getType() {
         return "Margherita";
      }
};
class Pepperoni : public Pizza {
   public:
      string getType() {
         return "Pepperoni";
      }
};
// Factory Method
class PizzaFactory {
   public:
      static Pizza* createPizza(string type) {
         if (type == "Margherita") {
            return new Margherita();
         } else if (type == "Pepperoni") {
            return new Pepperoni();
         } else {
            return nullptr;
         }
      }
};
// Builder
class PizzaBuilder {
   private:
      Pizza* pizza;
   public:
      PizzaBuilder() {
         pizza = nullptr;
      }
      void createPizza(string type) {
         pizza = PizzaFactory::createPizza(type);
      }
      Pizza* getPizza() {
         return pizza;
      }
};
// Singleton
class PizzaSingleton {
   private:
      static PizzaSingleton* instance;
      PizzaSingleton() {}
   public:
      static PizzaSingleton* getInstance() {
         if (!instance) {
            instance = new PizzaSingleton();
         }
         return instance;
      }
};
PizzaSingleton* PizzaSingleton::instance = nullptr;
int main() {
   PizzaBuilder builder;
   builder.createPizza("Margherita");
   Pizza* pizza = builder.getPizza();
   if (pizza) {
      cout << "Pizza Type: " << pizza->getType() << endl;
   } else {
      cout << "Invalid Pizza Type" << endl;
   }
   PizzaSingleton* singleton = PizzaSingleton::getInstance();
   return 0;
}





