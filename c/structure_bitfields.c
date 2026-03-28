
#include<stdio.h>

typedef struct {
int a:3;
int b:2;
int c:3;
int d:3;
int e:31;
}reg;

int main()
{
reg r ;
r.a= 5;
r.b= 6; 
r.c= 4;
r.d= -3;
r.e= 222;

printf("\n a=%d, b=%d, c=%d , d=%d", r.a , r.b, r.c, r.d);

 printf("\n sizeof(r) = %d",sizeof(r));
 //printf("\n sizeof(r.a) = %d",sizeof(r.a));
}