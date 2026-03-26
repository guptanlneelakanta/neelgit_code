/*
Write a function to print the following pattern.
The function takes the number of rows as an argument
Write only the function. Do not write main, scanf, #include etc.
The example shows the output for number of rows = 5
But the function shall work for any number of rows.
1
2  6
3  7  10
4  8  11  13
5  9  12  14  15
*/

#include<stdio.h>

void fun_print_tri_num(int rows)
{
    int k=0;
    for(int i=1; i<=rows; i++)
    {       
        k=i;
        for(int j=1; j<=i;  j++)
        {
            printf("%d ", k);           
            k+=rows-j;
        }
        printf("\n");
    }
}

int main()
{
    fun_print_tri_num(14);
}

