#include<iostream>
#include<memory>

using namespace std;

int main()
{
	shared_ptr < int> ptr1 = make_shared<int>(323);
	cout<<"shared ptr" << *ptr1<<endl;

	weak_ptr <int> ptr2 = ptr1;

	if(auto locked=ptr2.lock())
	{
	cout << *locked<< endl;
	}

	ptr2.reset();
	return 0;

}

