#include<iostream>
#include <memory>
using namespace std;

int main()
{

shared_ptr <int> sptr1 = make_shared<int>(100);

cout << "\n uptr1 value = " << *sptr1 << endl;
cout << "\n reference count value = " << sptr1.use_count() << endl;

shared_ptr<int> ptr2 = sptr1;
//unique_ptr<int> ptr3 = move(uptr1);
//cout << "\n ptr3 value" << *ptr3 << endl;
cout << "\n ptr2 value = " << *ptr2 << endl;
cout << "\n reference count value = " << ptr2.use_count() << endl;

unique_ptr <int> ptr4 = make_unique<int>(22);
*ptr4 = 4343;

cout<<"\n ptr4 = "<<*ptr4<<endl;
return 0;

}


