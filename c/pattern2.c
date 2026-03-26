
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
void pattern1(int num)
{
    int i=1;
    int k=0;

    while( i <=num )
    {        
        for(int j=0; j<i; j++)
        {
            if(j==0)
            k=i; 
            else if(j==1)
            k=i+num-j;
            else if(j==2)
            k=i+num+j;            
            else if(j>=3)
            k=i+num+j+1;            

            printf("%d ", k);
        }
            printf("\n");
        i++;
    }

}

void pattern2(int num)
{
    int i=1, j=0;
    int k=0;

    while( i <=num )
    {        
        k=i;
        for(j=1; j<=i; j++)
        {
            printf("%d ", k);
            k+=num-j;
        }
            printf("\n");
        i++;
    }

}
/**
 * 1   2  3  4  5
 * 16           6
 * 15           7   
   14           8
   13 12 11 10  9
 */
 void square_pattern(int rows)
{
    int total = rows*2+ (rows-2) *2;
    int i,j, pos;

    for(i=1; i<=rows; i++)
    {
        for(j=0; j<rows; j++)
        {
            if(i==1)
                pos = j+1; //top row
            else if(j==0)  // left colum
                pos = total+2 -i; 
            else if (j==rows-1) //right colum
                pos = rows+i-1; 
            else if (i==rows)
                pos = total+2-i-j; // bottom row
            else
            {
                printf("\t");
                continue;
            }
            printf("%d\t", pos);
        }   
        printf("\n");
    }
}

void square_pattern_chr(int rows)
{
    int total = rows*2+ (rows-2) * 2;
    int i,j, pos;

    for(i=1; i<=rows; i++)
    {
        for(j=0; j<rows; j++)
        {
            if(i==1)
                pos = j+1; //top row
            else if(j==0)  // left colum
                pos = total+2-i; 
            else if (j==rows-1) //right colum
                pos = rows+i-1; 
            else if (i==rows)
                pos = total+2-i-j; // bottom row
            else
            {
                printf("\t");
                continue;
            }
            pos=(pos%26);
            printf("%c\t", 'A' + pos-1);
        }   
        printf("\n");
    }
}


int main()
{
    //pattern1(5);
    //printf("\n\n");
    //pattern2(6);

    square_pattern(7);
    //square_pattern(12);
    square_pattern_chr(10);
    //square_pattern_chr(10);
}