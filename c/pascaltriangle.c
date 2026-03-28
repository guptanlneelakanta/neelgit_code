#include<stdio.h>
#include<math.h>

int main()
{
    int N=10;

    int i, j,k;
int x=1;
    for(i=1; i<=N; i++)
    {
        printf("\n");
        
        for(j=1; j<=(N-i); j++)
            printf(" ");

            x=1;
        for(j=1; j<=i; j++)
        {
            printf("%d ", x);
            
            x=x*(i-j)/j;
            
        }
    }
}
