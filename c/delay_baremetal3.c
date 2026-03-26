
/*
This is for a baremetal system (No operating system)
Write a function to provide delay in terms of milli seconds.
The processor provides a 32 bit free running counter register.
This is a read only register.
It increments every processor clock cycle.
The processor clock is 192 MHz
The counter register is at address 0xA0000000
Make use of this for impelmenting the delay function.
Write only the function and no other line of code.
*/

#include<stdio.h>

void delayfun(int m)
{
    volatile int *cnt = (volatile unsigned int *) 0xA0000000;

    //double clk=1.0/192000000;

    //int millisec = clk
    unsigned int start=*cnt;
    /*1 sec=192 m 
    1000 msec =192
    msec = 192 * 1000;
    *cnt=0;
    */
    unsigned int ticks =  m*192000;

    while((*cnt - start ) <= ticks);
}

int main()
{
    printf("\n before delay");
    delayfun(100);
    printf("\n after delay");
}