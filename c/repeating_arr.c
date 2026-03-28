#include<stdio.h>

void sort(int arr[], int sz)
{
    int temp;
    printf("\n sorted arr: \n");
    for(int i=0; i<sz; i++)
    for(int j=0; j<sz; j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }

    }

    for(int i=0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

void repeatingele(int arr[], int sz)
{
    printf("\n repeating elements: ");
    for(int i=0; i<sz; i++)
    {
   //         printf("m = %d ", arr[i]);
        while(i< sz && arr[i] == arr[i+1])
        {
            printf("%d ", arr[i]);
            break;
        }
    }
}

int main()
{
    int arr[] ={1,2,3,4,5,3,4,5,2};
    int sz=9;
    sort(arr, sz);
    repeatingele(arr, sz);
}

