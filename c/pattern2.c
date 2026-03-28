
/**
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
NOTE: do not use an array, print on the fly.
*/

#include<stdio.h>

void pattern(int rows)
{ 
    int i, j, val;
    printf("\n patter1   : \n");
    for(i=1; i<=rows; i++)
    {
        val =i;
        for(j=0; j<i; j++)
        {
            printf("%d ", val);
            val = val+rows-j-1;            
        }
        printf("\n");
    }    
}

/**
Write a function to print the following pattern.
The function takes the size of the square as an argument.
Write only the function. Do not write any other line of code.
The examples shows the output for size = 3 and size = 5.
But the function shall work for any given size.
The letter shall wrap around to A after Z.
IMPORTANT: do not use an array. Print on the fly.

Size = 3
A B C
H   D
G F E
*/
void pattern2(int rows)
{
 int i, j, val;
 int total=rows*2+ (rows-2)*2;

        printf("\n patter2   : \n");
    for(i=1; i<=rows; i++)
    {
        val =i;
        for(j=0; j<rows; j++)
        {
            if(i==1)
                printf("%c ", 'A' + j);
            else if(j==0)
                printf("%c ", 'A' + total-i+1);
            else if(j==rows-1)
                printf("%c ", 'A' + rows-1+i-1);
            else if(i==rows)
                printf("%c ", 'A' + total-rows-j+1);
            else 
                printf("  ");            
        }
        printf("\n");
    }    
}

void pattern3_num(int rows)
{
 int i, j, val;
 int total=rows*2+ (rows-2)*2;

    printf("\n patter2   : \n");
    for(i=1; i<=rows; i++)
    {
        val =i;
        for(j=0; j<rows; j++)
        {
            if(i==1)
                printf("%d  ", 1 + j);
            else if(j==0)
                printf("%d ", total-i+2);
            else if(j==rows-1)
                printf("%d ", 1 + rows-1+i-1);
            else if(i==rows)
                printf("%d ", 1 + total-rows-j+1);
            else 
                printf("   ");            
        }
        printf("\n");
    }    
}

/**
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

void pattern4_num(int rows)
{
 int i, j, val =rows* rows;;
 
    printf("\n patter2   : \n");
    for(i=1; i<=rows; i++)
    {        
        for(j=0; j<rows; j++)
        {
            printf("%d ", val--);
        }
        printf("\n");
    }    
}



int main()
{
   int rows=5;
   pattern(rows) ;
   pattern2(rows) ;   
   pattern3_num(rows);       

      pattern4_num(5);       
      pattern4_num(3);       
}




