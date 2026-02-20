
#include<iostream>
#include <memory>
using namespace std;
double division(int a, int b);


#include <exception>


struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 

int main()
{
    try{
    int m = division(5,0);
    }
    catch(const char *e)
    {
        cerr<<e<<endl;
    }

       try {
      throw MyException();
   } catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
   }

}


double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}