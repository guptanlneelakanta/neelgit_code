#include<iostream>
#include<string>
using namespace std;

int main()
{
string str = "MADAM";

string::iterator it;
int len = str.length();
int count=0;
for(int i=0, j=len-1; str[i]!= '\0'; i++)
{
    if(str[i] >= 97 &&  str[i] <=122 )
       str[i] = str[i] - 32;
}
cout<<"\n str = "<<str<<endl;
for(int i=48; i<140; i++)
cout<<" i = "<<i<<" "<<(char)i<<endl;
}