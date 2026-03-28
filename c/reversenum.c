#include<stdio.h>
#include<math.h>

int countdigits(int n)
{
    int cnt=0;
    while(n!= 0)
    {
        n=n/10;
        cnt++;
    }
    return cnt;
}

int reverse(int n)
{
    int ans =0;
    int cnt = countdigits(n);
    printf("\n cnt = %d", cnt);
    while(n!=0 )
    {
        if (cnt-- == 0)
        break;
        ans += (n%10)  * pow(10, cnt) ;
        n = n/10;
    }
    return ans;
}

int reverse2(int n)
{
    int ans =0;    
    while(n!=0 )
    {
        ans = ans *10 +  (n%10);
        n = n/10;
    }
    return ans;
}

int main()
{
int num = 345678;
    int n = reverse(num);
    printf("\n %d after reverse %d", num, n);

    int n2 = reverse2(num);
    printf("\n %d after reverse %d", num, n2);

}