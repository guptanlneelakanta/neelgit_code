#include<stdio.h>
#include<math.h>

int main()
{
    int N=5;

    int i, j,k;

    for(i=1; i<=N; i++)
    {
        printf("\n");
        
        for(j=1; j<=(N-i); j++)
            printf(" ");

        for(j=1; j<2*i; j++)
            printf("*");
    }
}
