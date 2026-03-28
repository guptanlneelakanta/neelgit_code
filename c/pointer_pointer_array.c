#include<stdio.h>
#include<malloc.h>

int main()
{

    int i=0, j=0;
    int rows=4, col=3;
    int **arr=(int **)malloc(rows * (sizeof(int)));

    for(i=0; i<4; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
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
        //printf("\n 0x%X =  %d",  &arr[i][j] ,arr[i][j]);
        printf(" 0x%X =  %d",  &arr[i][j] ,arr[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<4; i++)
        free(arr[i]);
    free(arr);
}