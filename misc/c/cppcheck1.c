#include<stdio.h>
#include<stdlib.h>

int main()
{

    int m; //Uninitialized Variables
   // m=34;

    int *ptr=malloc(4);

    free(ptr);

    *ptr=3243;  //dangling pointer
    printf("\n ptr= %d", *ptr);

    int *ptr2=NULL; 
    *ptr2=4354;            //null pointer dereference

    int arr[5];
    arr[8] = 434;   //bufferoverflow

    int k=0
    int m=67;
    m=m/k; 

    char buf[20];

    scanf("%s", buf);

    return 0 ;

    printf("\n hello main ends here");

}