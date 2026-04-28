#include<iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    unique_ptr ptr1=make_unique<int>(100);
    cout<<*ptr1<<endl;

    unique_ptr ptr2= move(ptr1);
    cout<<*ptr2<<endl;

    shared_ptr ptr3 = make_shared<double>(103.4450);
    cout<<*ptr3<<endl;
    cout<<"\n Reference count ptr3= "<<ptr3.use_count() <<endl;

    shared_ptr ptr4 =  ptr3;
    cout<<*ptr4<<endl;
    cout<<"\n Reference count ptr3= "<<ptr3.use_count() <<endl;
    cout<<"\n Reference count ptr4= "<<ptr4.use_count() <<endl;

    weak_ptr ptr5 = ptr4;
    if(auto locked = ptr5.lock())
    {
        cout<<"\n *ptr5 = "<<*locked<<endl;
    }
}