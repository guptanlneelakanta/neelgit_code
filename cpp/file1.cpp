#include<iostream>
#include<fstream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    char data[100];
    ofstream outf;

    outf.open("test1.txt");
    cout<<"enter your name:"<<endl;
    cin>>data;

    outf<<"wecome file handling "<<endl;
    outf<<data;
    outf.close();

    ifstream infile;
    infile.open("test1.txt");

    if (!inputFile) {
      std::cerr << "Error opening file!" << std::endl;
      return 1;
   }

    infile>>data;
    cout<<data;
    infile.close();
    
}
