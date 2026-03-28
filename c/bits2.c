

#include<stdio.h>

//11. Clear the last right side set a bit of a number

void clear_last_setbit(int num)
{
    int v = (num & (num -1));
    printf("\n v = 0x%x", v);
}


void power_of_2(int num)
{
    if((num & (num -1)) == 0)
      printf("\n num  = 0x%x is power of 2", num);
    else 
    printf("\n num  = 0x%x is not power of 2", num);
}


//13. Count the number of set bits in a number
void setbits_in_num(int num)
{
    int cnt=0;
    
    /*for(int i=0; i<32; i++)
    {
        if(num & 1<<i) ==  (1<<i))
        {
            cnt++;
        }
    }
        */
        while(num != 0)
        {
            cnt++;
            num &= num-1 ;
            printf("\n num =0x%x", num);
        }
        printf("\nnumber of 1 's in  cnt = %d", cnt);

}

//14. Swap two bits at a given position in an integer
void swap_at_position(int num, int i, int j)
{
    

}


int main()
{
int num = 144;

clear_last_setbit(num);

 power_of_2( num);

 num =16;
  power_of_2( num);

  num = 0xff;
  setbits_in_num(num);
}