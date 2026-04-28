#include<iostream>
#include <memory>
using namespace std;

class ClassB;

class ClassA{
	private:
	int dataA;
	
	public:
	ClassA(int a): dataA(a){}
	friend class ClassB;
};

class ClassB{
	private:
	
	public:
	void showdatafromA(ClassA &obj)
	{
		cout<< "\n obj.dataA ===" << obj.dataA <<endl;
	}

};

int main()
{

ClassA objA(34);
ClassB objB;

objB.showdatafromA(objA);

}
