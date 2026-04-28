#include<stdio.h>
#include<iostream>
#include<ctime>

void fun(int a[])
{
    for(int i=0; i<5; i++)
    printf("\n a[%d]=%d", i, a[i]);
}

void fun2(int *a)
{
    printf("\n sizeof(a) = %d", (int)sizeof(a));
    for(int i=0; i<5; i++)
    printf("\n a[%d]=%d", i, a[i]);
}


int * fun3()
{
    int *arr3 =(int *) malloc(sizeof(int) * 5);
  // set the seed
   srand( (unsigned)time( NULL ) );

    for(int i=0; i<5; i++)
    arr3[i] =rand();

    return arr3;
}

int main()
{
    int arr[]={4,5,6,7,8};

    printf("\n in main sizeof(arr) = %d", (int)sizeof(arr));
    printf("\n in main sizeof arr = %d", (int)sizeof(arr)/4);
    fun(arr);
    fun2(arr);
    int *arr4=fun3();

    for(int i=0; i<5; i++)
       printf("\n arr4[%d]=%d", i, arr4[i]);
}
