#include<stdio.h>

int * revarr(int arr[], int sz)
{
    int i=0;
    int k=0;
     k = (sz%2==0)? sz/2 : (sz/2)+1 ;
     printf("\nk=%d",k);
    for(int i=0; i< k; i++)    
    {
        int temp=arr[i];
        arr[i] = arr[sz-1-i];
        arr[sz-1-i] = temp;
    }
}

int main()
{
    int sz=5;
    int arr[5] = {1,2,3,4,5};
    
    revarr(arr, sz);

    for(int i=0; i<sz; i++)    
    {
        printf("\n Arr[%d] = %d", i, arr[i]);
    }
}

