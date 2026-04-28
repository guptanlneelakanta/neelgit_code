#include<stdio.h>
#define TEST(reg)  23  

int main()
{

int x= TEST(x);

if (-33 > 10)
printf("\n 10 greater");
else
printf("\n 10 smaller");


printf("\n %d", (5<<3)+5);

int num1=5, num2=8;

num1=num1 ^ num2;
printf("\nnum1  %d", num1);

num2=num1 ^ num2;
printf("\nnum2  %d", num2);

num1=num1 ^ num2;
printf("\nnum1  %d", num1);

num1=9;
num2=12;
num1^= num2^=num1 ^= num2;
printf("\nnum1  %d", num1);
printf("\nnum2  %d", num2);

num1=9;
num2=12;
num1= num1+num2;
num2 =num1- num2;
num1 =num1- num2;

printf("\nnum1  %d", num1);
printf("\nnum2  %d", num2);

num1=9;
num2=12;

num1 = (num1+num2)-(num2=num1);
printf("\nnum1  %d", num1);
printf("\nnum2  %d", num2);

int arr[3];
arr[0]=33;
arr[1]=33;
arr[2]=33;
//arr[3]=33;

int (*ptr)[10] = {2,3,4,5,6,7,8};


}
