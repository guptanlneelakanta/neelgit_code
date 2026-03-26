/*
Write a function to print the following pattern.
The function takes the number of rows as an argument
Write only the function. Do not write main, scanf, #include etc.
The example shows the output for number of rows = 5
But the function shall work for any number of rows.
1    2     3    4         5
16                          6
15                          7
14                          8
13   12    11   10    9   
NOTE: do not use an array, print on the fly.
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
                printf("\t");
                continue;
            }

            ch = 1 + pos ; //(pos % 26);
            printf("%d\t", ch);
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
    pattern(10);
    pattern2(5);
}