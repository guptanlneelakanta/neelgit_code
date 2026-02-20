
#include<iostream>


class Line{

public:
	void setlength(int l);
	int getlength();
	Line(int l){len= new int; *len=l;}
	Line(const Line &obj);

	
private:
	int *len;
	
};


void Line :: setlength(int l)
{
*len=l;
}

int Line :: getlength()
{
	return *len;
}

Line ::	Line(const Line &obj)
{
len = new int;


*len=*obj.len;
std::cout<<"\n copy constructor"<<std::endl;
}

void display(Line obj)
{
std::cout<<"display fun"<< obj.getlength() << std::endl;
}

int main()
{
Line line1(10);

line1.setlength(20);

int ret=line1.getlength();
std::cout<<"\n len="<<ret<<std::endl;
display(line1);
}

