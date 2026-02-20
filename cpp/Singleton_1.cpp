#include<iostream>
#include<string>
using namespace std;

class Logger{
    private:
        Logger() {}
       
    public:
        static Logger& getinstance(){
            static Logger object;            
            return object;
        }

        void log (string msg)
        {
            cout<<"\n the log message is "<<msg<<endl;
        }
};


int main()
{
    Logger &logger = Logger::getinstance();
    logger.log("test message");

    Logger &l1 = Logger::getinstance();
    l1.log("test message 2");    
    return 0;
}
