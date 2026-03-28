#include<stdio.h>
#include<malloc.h>

int main()
{

    int i=0, j=0;
    int rows=4, col=3;

    int *data=(int *)malloc(rows * col * (sizeof(int)));
    int **arr;

    for(i=0; i<4; i++)
    {
        *(arr+i) = &data[i * col];
    }
    
    int val=1;
    for(i=0; i<4; i++)
    for(j=0; j<4; j++)
    {
        arr[i][j] = val++;
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
        printf(" %d",  arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
}