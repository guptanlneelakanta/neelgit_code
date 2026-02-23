#include<iostream>
#include <exception>
#include<bits/stdc++.h>
using namespace std;

class NegativeValueException : public exception{
    private :
        int value;

    public:
    NegativeValueException(int v) : value(v){}

    const char* what() const noexcept override
    {
        return "Negative value error occurred!";
    }

    int getvalue()
    {
        return value;
    }
};

void checkval(int x)
{
    if(x<0)
        throw NegativeValueException(x);
    else
        cout<<"\n x = "<<x<<endl;
}

int main()
{
    try{
        int a=44, b=3; 
        int ch;
        cout<<"enter 1 for invalid_argument exception, 2 for out of range."<< endl;
        cin>>ch;
        if (ch=='1')
        {
            throw invalid_argument("invalid_argument");
        }
        else if (ch=='2')
        {
            throw out_of_range("out_of_range");
        }
        else
            throw "unknown_error";
    }
    catch(invalid_argument e)
    {
        cout<<"\nexception caught = "<< e<< endl;
    }
        catch(out_of_range e)
    {
        cout<<"\nexception caught = "<< e<< endl;
    }

     catch(...)
    {
        cout<<"\nexception unknown = " endl;
    }

    
}

