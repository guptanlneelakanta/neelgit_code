#include<stdio.h>

#define  LITTLE_TO_BIG(val)  val =  ( val  <<24) | ((val & 0xff00) <<8)| ((val & 0xff0000) >>8) |(val>>24)

#define setbit(reg, bitno) reg = reg | (1<<bitno) 
#define resetbit(reg, bitno) reg = reg & ~(1<<bitno) 
#define togglebit(reg, bitno) reg = reg ^(1<<bitno) 

#define writereg(reg, bitmsk, bitpos, val) reg |= ((reg & ~bitmsk) | (val <<bitpos) )


int main()
{
unsigned int val=0x12345678;

printf(" \n LITTLE_TO_BIG(val) = 0x%x", LITTLE_TO_BIG(val));

unsigned int  t=0 ;
unsigned int val2 =0x22334455;

t= ( val2  <<24) | ((val2 & 0xff00) <<8)| ((val2 & 0xff0000) >>8) |(val2 >> 24);
printf(" \n 4 t = 0x%x", t);

unsigned int reg=0x22334455;
int bitno=1;
setbit(reg, bitno);
printf("\n setbit reg =0x%x", reg);

resetbit(reg, bitno);
printf("\n resetbit reg =0x%x", reg);

togglebit(reg, bitno);
printf("\n togglebit reg =0x%x", reg);

togglebit(reg, bitno);
printf("\ntogglebit reg =0x%x", reg);
int bitmsk = 0x1f;
int bitpos = 5;
int val3 = 0x13; 
unsigned int reg2 = 0x34560000;
writereg(reg2, bitmsk, bitpos, val3) ;
printf("\n writereg reg2 =0x%x", reg2);


}