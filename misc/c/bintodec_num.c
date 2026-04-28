//6. Write a Program to convert the binary number into a decimal number.

#include<stdio.h>
#include<math.h>

int main()
{
    int N =10111;

    int ans=0;
    int bitpos=0;
    int t=0;

    while(N!=0)
    {
        t=N%10;
        ans = ans + t* pow(2, bitpos);
        bitpos++;
        N=N/10;
    }

    printf("\n ans =%d\n", ans);

}