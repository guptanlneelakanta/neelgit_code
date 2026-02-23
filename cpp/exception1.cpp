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
        if(a%b != 0)
        {
            throw -1;
        }
    }
    catch(int e)
    {
        cout<<"exception caught = "<< e<< endl;
    }
    int a[5] = {2, 3, -5, 6, -7};

    try{
        
        for(auto i : a)
        {
            checkval(i);
        }
    }

    catch(NegativeValueException(&i))
    {
        cout<<"error = " <<i.what()<<
        i.getvalue()<< endl;    
    }        

    vector<int> v1={3,5,6};
    try{
        v1.at(10);
    }
    catch(out_of_range e)    
    {
          cout<< "\n caught :"<<e.what()<<endl;
    }
}

