#include<stdio.h>
#include<stdlib.h>

int* fun()
{
    int *ptr=malloc(sizeof(int));
    *ptr=323;
    return ptr;
}

int main()
{

    int *p2=malloc(sizeof(int));
    *p2=456;
    printf("\n *p2=%d \n", *p2);

    int p3_1 = 456;

    /** pointer to const int */
    const int *p3 =&p3_1; 
    
    printf("\n *p3=%d \n", *p3);

    /** const pointer to int */
    int *const p4=malloc(sizeof(int));
    *p4=456;
    printf("\n *p4=%d \n", *p4);

    int *p5=fun();
    printf("\n fun calling=");
    printf("\n *p5=%d \n", *p5);

    int *ptr=NULL;
    // *ptr=323;
    //printf("\n *ptr=%d", *ptr);

    int arr[5]={1,2,3,4,5};
    //pointer to arry
    int (*ptrarr)=arr;

    printf("\n arr = %ls \n", arr);
    

    for(int i=0; i<5; i++)
        printf("\n ptrarr[%d] = %d", i, ptrarr[i]);

    int (*ptrarr2)[5] = &arr;

    for(int i=0; i<5; i++)
        printf("\n ptrarr2[%d] = %d", i, (*ptrarr2)[i]);

        //3*4 array
        int *data = (int *)malloc(sizeof(int) *3*4);
        int **p10=(int **)malloc(sizeof(int) *3);

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
}

