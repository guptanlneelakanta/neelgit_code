#include<stdio.h>

void printdata(char *buf)
{
    printf("\n %s", buf);
}

int main()
{
  char buf[] = "Hello World!\n";
  printdata(buf);
  return 0;
}