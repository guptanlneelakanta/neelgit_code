
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
*/
#include<stdio.h>

void pattern1(int rows)
{

int val=0;

    for(int i=1; i<=rows; i++)
    {        
        val=i;
        for(int j=0; j<i; j++)
        {
            printf("%d ", val);
            val=val + rows -j -1;
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

int val=0;
char c;
    for(int i=1; i<=rows; i++)
    {        
        val=i;
        for(int j=0; j<rows; j++)
        {
            if(i==1)
                c = 'A' + j;
            else if(j==0)
                c = 'A' + j;
            else if(j==rows-1)
                printf("%c ", 'A' + j);
            else if(j==rows)
                printf("%c ", 'A' + j);
            else 
            {
                printf("  ");  
                continue;
            }            
            printf("%c ", c);
        }
        printf("\n");
    }
}

void print_pattern3(int n) {
    int total = 4 * (n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            if (i == 0)                  c =   j;
            else if (j == n - 1)         c =  (n - 1) + i;
            else if (i == n - 1)         c =  (total - i - j) % total;
            else if (j == 0)             c =  (total - i) % total;
            else { printf("  "); continue; }
            //printf("%c ", c % 26 + 'A' - (c >= 'A' + 26 ? 26 : 0));

            printf("%c ", c % 26  + 'A' );
        }
        printf("\n");
    }
}


void print_pattern_num4(int n) {
    int total = 4 * (n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            if (i == 0)                  c =   j;
            else if (j == n - 1)         c =  (n - 1) + i;
            else if (i == n - 1)         c =  (total - i - j) % total;
            else if (j == 0)             c =  (total - i) % total;
            else { printf("  "); continue; }
            //printf("%c ", c % 26 + 'A' - (c >= 'A' + 26 ? 26 : 0));

            printf("%d ", c+1 );
        }
        printf("\n");
    }
}

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

void print_pattern_num5(int n) {
    int num = n*n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {          
            printf("%d ", num-- );
        }
        printf("\n");
    }
}

int main()
{
  pattern1(5);
pattern1(7);

print_pattern3(3);
  //printPattern(5);
   print_pattern_num4(4) ;
    print_pattern_num5(5) ;
}