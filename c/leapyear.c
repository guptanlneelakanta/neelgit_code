#include<stdio.h>
//#include<math.h>

void leap_check(int year);
int main()
{
    int year =2004;
 printf("\n leap year prog");  
    leap_check(2400);
    leap_check(2008);
    leap_check(2002);
}


void leap_check(int year)
{
 if(year%4 == 0)
    printf("\n year %d is leap ", year);
else 
     printf("\n year %d is not leap ", year);
}