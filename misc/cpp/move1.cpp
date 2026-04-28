#include<iostream>
using namespace std;

int main()
{

string a = "Hello";
string b = std::move(a); // 'a' is moved, not copied

std::cout<<a<<std::endl;
std::cout<<b<<std::endl;

}


