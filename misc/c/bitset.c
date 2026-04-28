#include<stdio.h>

#define BITSET(reg, bitnm) reg |= (1<< bitnm) 
#define BITRESET(reg, bitnm) reg &= ~(1<< bitnm) 

#define WRITEREG(reg, bitfd_S, bitsiz, data ) reg &= (~( bitsizmask << (bitfd_S - bitsiz + 1)   | )) 

int main()
{
	int reg=0x3456;
	printf("\n reg = %x",reg);
	
	BITSET(reg, 0) ; 	
	printf("\n reg = %x",reg);
	
	BITRESET(reg, 0) ; 	
	printf("\n reg = %x",reg);
	
	reg &= (5<<4); 
	printf("\n reg = 0x%x",reg);
	
}


