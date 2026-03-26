/*
Write a C function that takes a null terminated string as the only one argument
When the function returns, the string will be reversed.
Do not call any other function from this function.
Use at the most two local variables. Restrict to one variable if you can.
This shall work for string of any length.
The return type of the function is void.
Write only the function no other line of code.

 

[ 'a', 'b', 'c', '\0']
*/
#include<stdio.h>
#include<string.h>
void rev_str(char *str)
{
    char *end = str;
    char temp;
    while(*end != '\0')
    end ++;

    end--;

    while(end>str)
    {
        temp= *str;
        *str=*end;
        *end = temp;       
        str++;
        end--; 
    }
   // str[5]=0;
}

int main()
{
    char str[] = "hellogood";
    rev_str(str);
    printf("\n%s \n ", str);

}