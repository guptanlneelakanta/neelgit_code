#include<stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define check_bit(var, bitnum)   var&(1<<bitnum) 
#define swap_16bit(var)  ((var& 0xff)<<8 | (var& 0xff00) >>8)
#define swap_32bit(var)  (((var& 0xff) <<24) | ((var& 0xff000000) >>24) | ((var& 0x00ff0000) >>8) | ((var& 0x0000ff00) <<8))

void num_even_or_odd(int num)
{
    if((num & 1) == 0)
    {
        printf("\n num %d is even", num);
    }
    else 
    {
        printf("\n num %d is odd", num);
    }
}

int* fun1()
{
    int *var = malloc(sizeof(int)* 100);
    if(var==NULL)
    {
        printf("\n error memory not allocated.");        
        return NULL;
    }
    for(int i=0; i<100; i++)
    *(var+i)=556 + i;
    return var;
}

int add(int a, int b)
{
    return a+b;
}


int mul(int a, int b)
{
    return a*b;
}



int main()
{
    // Enable automatic memory leak checking at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
  int *res;
  res=fun1();
  printf("\n res= %d",res);
  //for(int i=0; i<100; i++)
  //printf("\n res=%d", *(res+i));
   // free(res);

   // array of function pointers
   int (*funptr[2])(int a, int b) = {add, mul };

   printf("\n funptr[0](4,5) = %d", funptr[0](4,5)); 
   printf("\n funptr[1](4,5) = %d \n", funptr[1](4,5)); 
   
   int arr1[]={33,44,5,66,7};

   int (*ptr1)[5] = &arr1;

   for(int i=0; i<5; i++)
   {
     printf("\n %d ", (*ptr1)[i]);
    }
    printf("\n Address of arr1: %p\n", (void*)&arr1);
    printf("\n 2Address of arr1: %p\n", arr1);

    printf("Value of ptr1:   %p\n", (void*)ptr1);
    printf("Value of ptr1:   %p\n", (*ptr1)[0]);


    //array of pointers
    int m=44, n=33;
    int *ptr2[2] = {&m, &n};
    printf("\n //array of pointers");
    printf("\n *ptr2[0] = %d", *ptr2[0]);
    printf("\n *ptr2[1] = %d", *ptr2[1]);

    int p=0x349;
    if(p & (1<<3) == 0)
    {
        printf("\n bit not set");
    }
    else 
    {
        printf("\n bit set = %d", (p & (1<<3)));
    }
int var = 0x3344;
    var = swap_16bit(var);
    printf("\n after swap = 0x%x", var);

    var=0x11223344;
    var = swap_32bit(var) ;
    printf("\n after swap 32bit  = 0x%x", var);

    int num =123;
    num_even_or_odd( num);

    num =122;
    num_even_or_odd( num);
}

