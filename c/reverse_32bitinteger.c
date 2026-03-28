#include<stdio.h>

int main()
{
    int data=0x5643, data2=0, data3=0;
    for(int i=0; i<16; i++)
    {
        data2 <<= 1;
        data2 |= (data & 1);        
        data>>=1;
    }
    printf("\n 0x%x",data2);
    
    data=0x12345643;
    data2=0;
    int res;
    for(int i=0; i<32; i++)
    {
        res = (data & 1)? 1: 0;
        //printf("\n%d",res);
        if(res)  
        {      
        data3 = (data3 | (1 << 31-i));                
        }
        else
        {
        data3 = (data3 & ~(1 << 31-i));                
        }
      //  printf("\n data3=0x%x",data3);
        data>>=1;
    }
    printf("\n 0x%x",data3);
}