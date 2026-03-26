/*
Write a function to print the following pattern.
The function takes the number of rows as an argument.
Write only the function. Do not write any other line of code.
The examples shows the output for number of rows = 5 and 3
But the function shall work for any number of rows.


IMPORTANT: Use only one local variable
nrow = 5
25  24  23  22  21
20  19  18  17  16
15  14  13  12  11
10  9  8  7  6
5  4  3  2  1
*/
#include<stdio.h>

void pattern1(int num)
{
    int i=num*num;
    while(i!=0)
    {
        printf("%d ", i--);       
        if(i%num ==0) 
        printf("\n");
    }
}

int main()
{
pattern1(5);
  printf("\n\n");
pattern1(3);
}