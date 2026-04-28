#include<stdio.h>
#include<stdlib.h>

int fun(int *s)
{
  printf("\n *s == %d\n", *s);

  return *s;
}

int* fun2()
{ 
  int *s  =(int *)malloc(4);
    *s=788;

  
  printf("\n s == %d\n", *s);

    return s;
}

int main()
{  
  int *p = (int*)malloc(4);
  *p=89;
  int r= fun(p);
  printf("\n %d  \n", r);

  int *m= fun2();
  printf("\n m = %d  \n", *m);


}


