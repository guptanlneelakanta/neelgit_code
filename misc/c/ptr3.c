#include<stdio.h>
#include<stdlib.h>

int main()
{
        //3*4 array
        int *data = (int *)malloc(sizeof(int) *3*4);
        int **p10=(int **)malloc(sizeof(int *) *3);

        for(int i=0; i<3; i++)
        p10[i] = &data[i*4];

        for(int i=0; i<3; i++)
        for(int j=0; j<4; j++)
        {
            *(*(p10+i) + j) = j;
            printf("\n p10[%d][%d] = %d", i, j, *(*(p10+i) + j));
        }

        int m1, m2;
        int *arr2[2] = {&m1, &m2};
        m1=323;
        m2=456;

        printf("\n arr2[0] = %d \n", *arr2[0]);
        printf("\n arr2[1] = %d \n", *arr2[1]);     
        free(data);   
        free(p10);
}