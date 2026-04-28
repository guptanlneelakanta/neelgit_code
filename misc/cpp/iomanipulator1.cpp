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


int main(){
 Animal a;
   a.makeSound(); 
   a.breathe();   

   int num =323;
   int negnum = -434;

   cout<<"\n Left alig : "<<left<<setw(5)<<num<<endl;
   cout<<"\n Right alig : "<<right<<setw(5)<<negnum<<endl;
   cout<<"\n Right alig : "<<internal<<setw(5)<<negnum<<endl;

   double flt=32323.43434;

   cout<<"\n flt num = "<<flt<<endl;
   cout<<"\n flt num = "<<setprecision(7)<<flt<<endl;
   cout<<"\n flt num = "<<fixed<<flt<<endl;
   cout<<"\n flt num = "<<scientific<<flt<<endl;

   cout<<"original number = "<<num<<endl;
   cout<<"decimal = "<<dec<<num;
   cout<<"  oct  = "<<oct<<num;
   cout<<"  hex  = "<<hex<<num<<endl;

   cout<<"set base using setbase() = "<<num<<endl;
   cout<<"base 10 = "<<setbase(10)<<num;
   cout<<"base 8 = "<<setbase(8)<<num;
   cout<<"base 16 = "<<setbase(16)<<num<<endl;

   cout<<"hide prefix using noshowbase() = "<<num<<endl;
   cout<<noshowbase;
   cout<<" base 10 = "<<setbase(10)<<num;
   cout<<" base 8 = "<<setbase(8)<<num;
   cout<<" base 16 = "<<setbase(16)<<num<<endl;

   cout<<"show prefix using showbase() = "<<num<<endl;
   cout<<showbase;
   cout<<" base 10 = "<<setbase(10)<<num;
   cout<<" base 8 = "<<setbase(8)<<num;
   cout<<" base 16 = "<<setbase(16)<<num<<endl;
num = 45678;
      cout<<"lowercase using nouppercase() = "<<num<<endl;
      cout<<" base 10 = "<<setbase(10)<<nouppercase<<num;
   cout<<" base 8 = "<<setbase(8)<<nouppercase<<num;
   cout<<" base 16 = "<<setbase(16)<<nouppercase<<num<<endl;

   cout<<"uppercase using uppercase() = "<<num<<endl;
      cout<<" base 10 = "<<setbase(10)<<uppercase<<num;
   cout<<" base 8 = "<<setbase(8)<<uppercase<<num;
   cout<<" base 16 = "<<setbase(16)<<uppercase<<num<<endl;
   return 0;
}