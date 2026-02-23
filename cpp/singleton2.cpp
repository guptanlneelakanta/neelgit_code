#include<iostream>
using namespace std;

class Singleton2{
    private: 
        Singleton2() {}
        Singleton2(const Singleton2&) = delete;
        Singleton2& operator=(const Singleton2&) = delete;
static int m[4];
    public:

        static Singleton2& getinstance()
        {
            static Singleton2 obj;
            return obj;
        }
        void log()
        {
            int m3;
            cout<<"\n singleton class"<<endl;
        }

         void log3()
        {
            int m3;
            cout<<"\n singleton class"<<endl;
        }
};

int main()
{
    Singleton2 &sig2 = Singleton2::getinstance();
    Singleton2 &sig3 = Singleton2::getinstance();

   // Singleton2 sig3;
    sig2.log();
   
    cout<<&sig2<<endl;
    cout<<&sig3<<endl;
    
    cout<<sizeof(sig2);
    cout<<"\n"<<sizeof(sig3);
    
    return 0;
}

