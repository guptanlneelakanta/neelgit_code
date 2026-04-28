#include<stdio.h>
#include<math.h>

int main()
{

    int N=102301;
int ans=0;
int cnt=0;
    while(N != 0)
    {
        if (N%10 == 0 )
        {
            ans = ans + 1 * pow(10, cnt);
        }
        else
        {
            ans += (N%10)* pow(10, cnt);
        }        
cnt++;
        N=N/10;   
    }

    printf("%d", ans);

}