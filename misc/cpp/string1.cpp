#include<iostream>
#include<string>
using namespace std;

int main()
{
string str = "welcome";

string::iterator it;

int count=0;
for(it=str.begin(); it!= str.end(); it++, count++)
{
    cout<<*it; 
}

cout<<"\n count is ="<<count <<endl;

for(char i:str)
    cout<<i;

cout<<str.length()<<endl;
cout<<str.size()<<endl;

string name="john";
string name2="linkon";
cout<<"\n name : "<<name<<endl;
name.swap(name2);

cout<<"\n name2 after swap : "<<name<<endl;

cout<<"\n resize -----"<<endl;
name.resize(name.size()+2, 'D');

cout<<name<<endl;

string str2="welcome to bangalore city";

int pos = str2.find("bangalore");
cout<<"\npos = "<<pos<<endl;

pos = str2.find("bangalore", 5);
cout<<"\npos = "<<pos<<endl;

str2.push_back('h');
cout<<"\nstr2 = "<<str2<<endl;

str2.pop_back();
cout<<"\nstr2 = "<<str2<<endl;

str2.clear();
cout<<"\nstr2 = "<<str2<<endl;

 std::string base="this is a test string.";
std::string str5="n example";
std::string str3="sample phrase";
std::string str4="useful.";

std::string st=base;

std::cout << st << '\n';
st.replace(9,5,str5);
std::cout << st << '\n';

st.replace(19,6,str3,7,6);
std::cout << st << '\n';

st.replace(8,10,"just a");
std::cout << st << '\n';

st.replace(8,6,"a shorty",7);
std::cout << st << '\n';

st.replace(22,1,3,'!');
std::cout << st << '\n';

st.replace(st.begin(), st.end()-3, str3);
std::cout <<"\n test = "<< st << '\n';

st.replace(st.begin(), st.begin()+6,"replace");
std::cout <<"\n test2 = "<< st << '\n';

st.replace(st.begin()+8, st.begin()+14,"is coolness",7);
std::cout <<"\n test3 = "<< st << '\n';
st.replace(st.begin()+12, st.end()-4,4,'o');

std::cout <<"\n test4 = "<< st << '\n';

st.replace(st.begin()+11, st.end(),str4.begin(),str4.end());
std::cout << st << '\n';

}