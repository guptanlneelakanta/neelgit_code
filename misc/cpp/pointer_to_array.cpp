#include<iostream>
#include<array>

using namespace std;

int disp(int a)
{
    cout<<"a = "<<a<<endl;
    return 0;
}

void printarr(int arr[], int siz)
{
    for(int i=0; i<siz; i++)
        cout<<"\n arr["<<i<<"] = "<<arr[i]<<endl;
}

int * arrretfromfunc(void)
{
    int num;
    static int arr3[10];
    srand((unsigned )time(NULL));

    for(int i=0; i<10; i++)
        arr3[i] = rand();
    return arr3;
}


int main()
{
    double arr[] = {33.45, 44.67, 55.66, 77.89};

    double *ptr;
    //pointer to array
    ptr= arr;   

    double  (*p)[4];
    p=&arr;

    for(int i=0; i<4; i++)
        cout<<*(*p+i) << " ";
cout<<endl;

int arr23[4][3] = {3,4,5,6,7,8,9,10,11,12,13,14};
int (*pp2)[3] = arr23;

cout<<"\n 2 dimentional array"<<endl;
for(int j=0; j<4; j++)
    for(int i=0; i<3; i++)
        cout<<*(*(pp2+j)+i) << " ";

cout<<endl;


    for(double i : arr)
        cout<<i<< " ";
cout<<endl;
    for(int j=0; j<4; j++)
        cout<< *(ptr+j)<< " ";
cout<<endl;
        //array of pointers

    int a=33, b=44, c=55;
    int *arr2[3] = {&a, &b, &c};

    cout<<"arr2[0] = "<<*arr2[0]<<endl;
    cout<<"arr2[1] = "<<*arr2[1]<<endl;
    cout<<"arr2[2] = "<<*arr2[2]<<endl;

    //pointer to an array of 5 integers
    int ptr3[5]= {44, 5, 66, 7, 8};
    int (*ptr4)[5]= &ptr3;
    cout<<"\narr3[2] = "<< (*ptr4)[2]<<endl;

    int (*func)(int a);
    func = disp;

    //func pointer called.
    cout<<"func pointer called."<<endl;
    func(5);

    //pointer to const int  --- int data is const and pointer can change.
    int x=667;
    int y=67;
    const int *ptr12 = &x;
    cout<<"\n *ptr12 = "<<*ptr12<<endl;
    const int *ptr13=&y;
    //*ptr12=12;  not works
    ptr12=ptr13; //works
    cout<<"\n *ptr12 = "<<*ptr12<<endl;

//const pointer to int  --- int data is not const and pointer is const.
    int m=667;
    int *const ptr31 = &m;
    cout<<"\n *ptr31 = "<<*ptr31<<endl;
    int *const ptr32 = &y;
    //ptr31 = ptr32;     //not works
*ptr31 = y;
    cout<<"\n *ptr31 = "<<*ptr31<<endl;

    int arr3[5] = {44,5,66,7,8};
    printarr(arr3, 5);

    //array return from function
    int *randarr = arrretfromfunc();

    for(int i=0; i<10; i++)
    cout<<randarr[i]<< " ";
    cout<<endl;
}

