/*
Question 1:

Write a C function that takes a null terminated string as the only one argument

When the function returns, the string will be rotated one position to the right.

Example: "hello world" -> "dhello worl"

Do not call any other function from this function.

Use at the most two variables apart from the function argument.

This shall work for string of any length.

The return type of the function is void.

Write only the function no other line of code.
*/

#include<stdio.h>
void strhandle(char *str)
{
    char *end =str;
    char temp=0;    
    while(*end)
    {
        end++;
        temp++;
    }
    end--;

    temp= str[0];            
    str[0] = *end;    
    str++;
    
    while(*str!=0)
    {
        *end = *str;
        *str = temp;   
        temp=*end;
        str++;                  
    }
}

int main()
{
    char str[] ="welcome";
    strhandle(str);
    printf("\n str=%s \n", str);
}