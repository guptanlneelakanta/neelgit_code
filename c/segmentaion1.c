#include<stdio.h>
#include<malloc.h>

int main()
{
int *p=(int *)malloc(120);
free(p);

*p=434; //segmentation fault
printf("\n *p =%d",*p);

int *p2=NULL;
free(p2);
*p2 = 434; //segmentation fault

//Buffer Overflow
char buf[10];
buf[20] = 'A';  // segmentation fault

//Writing to Read-Only Memory
char *s = "hello";
s[0] = 'H';  // segmentation fault

int *p3=(int *)43434;
*p3=43;
}

