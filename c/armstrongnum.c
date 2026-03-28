/*An Armstrong number (also called a Narcissistic number) is a number that is equal to the sum of its own digits raised to the power of the number of digits.

Definition

For a number with n digits:
n = number of digits

Example 1: 153

Digits = 1, 5, 3
Number of digits = 3

an = pow(1,3)+pow(5, 3) + pow(3, 3)
=153

So 153 is an Armstrong number.
*/

#include<stdio.h>
#include<math.h>

int countdigits(int n)
{
    int cnt=0;
    while(n!=0)
    {
        cnt++;
        n=n/10;
    }
    return cnt;    
}

int main()
{
    int n=153;
int ans =0;
int cnt=0;
int n2=n;
int num=n;
    
    while(n2!=0)
    {
        ans = ans + pow(n2 % 10, cnt);
        n2=n2/10;
    }

    if (ans == num)
        printf("\n num %d is armstrong", num);
    else 
        printf("\n num %d is armstrong", num);

}
