#include<stdio.h>
#include<stdlib.h>

void fun()
{
    int *p2=NULL;
    //int *p2=malloc(sizeof(int));
    *p2=6565;
    printf("\n value of p2 = %d", *p2);
} 

int main()
{
    int *ptr = NULL;
//    *ptr=2342;
    
    int p3=2342;
    printf("\n value of ptr = %d", p3);
    fun();
    return 0;
}

