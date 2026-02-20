#include<iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class Stack{

    private:
        vector <T> elems;

    public:
      void push(T const & a);
      void pop();
     T const&  top() const;
     bool empty() const
     {
        return elems.empty();
     }
};

template<class T>
void Stack<T>::push(T const & a)
{
    elems.push_back(a);
}

template<class T>
void Stack<T>::pop()
{
    if(elems.empty())
    {
        throw out_of_range("\n stack pop(), empty stack");
    }
    elems.pop_back();
}


template<class T>
T const&  Stack<T>::top() const
{
    if(elems.empty())
    {
        throw out_of_range("\n stack top(), empty stack");
    }
    return elems.back();
}

int main()
{
    try{

        Stack<int> stackint;

        stackint.push(5);
        stackint.push(7);
        stackint.pop();
        cout<<"int t= "<< stackint.top();

        Stack<string> stackstr;
        stackstr.push("welstr1");
        stackstr.push("welstr2");

        cout<< "\n stackstr.top() = "<<stackstr.top()<<endl;
        stackstr.pop();
        cout<< "\n stackstr.top() = "<<stackstr.top()<<endl;
        cout<< "\n stackstr.top() = "<<stackstr.top()<<endl;

    }

    catch(exception const &ex)
    {
        cerr<<"\n exception ex= "<<ex.what()<<endl;
        return -1;
    }
    
}
