#include<stdio.h>
#include<stdlib.h>

int fun1(int a, int b)
{
    return a+b;
}

int add (int a, int b)
{
    return a+b;
}

int mul (int a, int b)
{
    return a*b;
}

int main()
{
    int (*funptr2[2])(int m, int n) = {add, mul};

    int (*funptr)(int m, int n);

    funptr=fun1;

    int z=funptr(4,5);
    printf("\n z=%d \n",z);

    int *p1 = malloc(sizeof(int));

    const int *p2  = malloc(sizeof(int));
    *(int *)p2=323;
        *(int *)p2=3255;
    int *const p3  = malloc(sizeof(int));
    *p3 =434;

    int temp =323;
    const int *const p4  = &temp;
    
    //pointer to array
    int arr[5]={4,5,6,7,8};
    int (*ptrarr)[5] ;
    ptrarr=&arr;

    for(int i=0; i<5; i++)
    printf("\n ptrarr[%d] = %d", i, (*ptrarr)[i]);
    
    printf("\n");

    printf("\nadd = %d\n", funptr2[0](4,6));
    printf("\n mul= %d\n", funptr2[1](4,6));

    int m=33,n=55;

    int *arr2[2] ={&m, &n};  //array of pointers
    printf("\n arr2= %d\n", *arr2[0]);
    printf("\n arr2= %ld\n", arr2[1]);

}