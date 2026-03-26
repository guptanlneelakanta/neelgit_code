/*
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

Size = 5
A B C D E
P       F
O       G
N       H
M L K J I

TX - 7 bits

Rx node - 8 bits.'

Transmit letter A.
*/

#include<stdio.h>

void pattern(int n)
{
    int i, j;
    int total = 4 * (n - 1);
    int pos, ch;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0)                      // top row
                pos = j;
            else if (j == n - 1)             // right column
                pos = (n - 1) + i;
            else if (i == n - 1)             // bottom row
                pos = 3 * (n - 1) - j;
            else if (j == 0)                 // left column
                pos = total - i;
            else
            {
                printf("   ");
                continue;
            }

            ch = 'A' + (pos % 26);
            printf("%c  ", ch);
        }
        printf("\n");
    }
}


void pattern2(int sz)
{
    int pos=0;
    int total=sz*sz-(sz-2)*(sz-2);
    for(int i=0; i<sz; i++)
    {     
        for(int j=0; j<sz; j++)
        {
            if(i==0) //first row
            {
                //printf("%c ", 'M');
                pos = j;
            }
            else if(j == (sz-1))  //right col                
            {
                //printf("%c ", 'N');
                //pos = j + sz*i;
                pos = sz-1 + i;
            }
            else if(j == 0)  //left col
            {
                //printf("%c ", 'p');
                //pos = sz * i;
                pos = total-i;
            }
            else if(i == sz-1)  //bottom row
            {
                //printf("%c ", 'q');
                //pos = sz*i+j;
                pos = total - i-j;
            }
            else
            {
              printf("  ") ;
              continue;
            }
            //printf("%d ", pos);    
            //if(i=0 || i==sz-1 || j==0 || j==sz-1)
            printf("%c ", 'A' + (pos%26))  ;
        }
        printf("\n");
    }
}


int main()
{
    //squarechar_fun(3);
    pattern(3);
    pattern2(5);
}