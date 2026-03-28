#include<stdio.h>

void swap(int *x, int *y)
{
    *x^=*y;
    printf("\n x=%d y=%d",*x,*y);
    *y^=*x;
    printf("\n x=%d y=%d",*x,*y);
    *x^=*y;
printf("\n x=%d y=%d",*x,*y);
}

void swaparr(int *x, int *y, int size)
{
    for(int i=0; i<4; i++)
    {
        x[i]^=y[i];
        y[i]^=x[i];
        x[i]^=y[i];
    }
}

int main()
{

    int x=33, y=45;
    swap(&x, &y);
    printf("\n x=%d y=%d",x,y);

    int arr1[4] = {44,5,66,7};
    int arr2[4] = {14,15,6,17};
int size=4;
    swaparr(arr1, arr2, size);
    
    for(int j=0; j<4; j++)
    printf(" arr1=%d ",arr1[j]);

    for(int j=0; j<4; j++)
    printf(" arr2=%d ",arr2[j]);
}