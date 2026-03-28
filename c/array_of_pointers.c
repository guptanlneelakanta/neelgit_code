#include<stdio.h>
#include<stdlib.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
    int a=4,b=5,c=6;

    int *p[3] = {&a, &b, &c};

       _CrtDumpMemoryLeaks();  // report leaks    

    for(int i=0; i<3; i++)
        printf("\n *p[%d] = %d", i, *p[i]);

    int *ptr2 = calloc(5, sizeof(int));
    int *ptr3 = malloc(5*sizeof(int));

    for(int i=0; i<5; i++)
        printf("\nptr2 = %d", *(ptr2+i));

    for(int i=0; i<5; i++)
        printf("\nptr3 = %d", *(ptr3+i));
free(ptr2);
free(ptr3);
   
}