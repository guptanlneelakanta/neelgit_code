#include<iostream>
#include<stdexcept>
using namespace std;        

int main()
{
    try
    {
        int a = 10;
        int b = 0;
        if (b == 0)
        {
            throw runtime_error("Division by zero is not allowed");
        }
        int c = a / b;
        cout << "Result: " << c << endl;
    }
    catch (const runtime_error& e)
    //catch (const char * m)
    {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}