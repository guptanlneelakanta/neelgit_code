#include<stdio.h>

int gcd(int a, int b)
{

    int res= (a<b)? a: b;

    while(res>0)
    {
        if(a % res == 0 && b % res == 0)
        {
          printf("\n gcd is = %d", res);              
          break; 
        }        
        res--;
    }
    return res;
}

int main()
{
    int val = gcd(98, 56);
    printf("gcd val = %d",val);
}