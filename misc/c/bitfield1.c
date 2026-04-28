#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define REG32(addr)    (*(volatile uint32_t *)(addr))

#define SET_BIT(reg, bit)       ((reg) |=  (1U << (bit)))
#define CLEAR_BIT(reg, bit)     ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit)    ((reg) ^=  (1U << (bit)))
#define READ_BIT(reg, bit)     (((reg) >>  (bit)) & 0x1U)

#define GPIOA_ODR   REG32(0x48000014)

//mask is bitfield mask  if bif=tfield size is 3 bits  then mask is 7
//pos is last bit position in the bitfield 
#define WRITE_FIELD(reg, mask, pos, value) \
        (reg) = ((reg) & ~(mask << pos)) | (value<< pos); 

//concatenation operator in c
#define CUSTOM_MACRO(x, y) x##y

int main()
{

	int reg=0x4343;
	uint32_t *p = (int *)malloc(sizeof(uint32_t));
	
	printf("\n reg= 0x%x", reg);
	SET_BIT(reg, 2);
	printf("\n reg= 0x%x", reg);

	CLEAR_BIT(reg, 2);
	printf("\n reg= 0x%x", reg);

	TOGGLE_BIT(reg, 2);
	printf("\n reg= 0x%x", reg);
	
	READ_BIT(reg, 2);
	printf("\n reg= 0x%x", reg);
	
	if(READ_BIT(reg, 2))
		printf("\n bit 1");
	else
		printf("\n bit 0");
		
	*p=0x4507;  // 0100 0101
	printf("\n *p= 0x%x", *p);
	
	char pos = 8; 
	int mask=7;
	int val = 1;
	WRITE_FIELD(*p, mask, pos, val);    //write bitfield position 10:8   
	
	printf("\nWRITE_FIELD *p= 0x%x", *p);


	REG32(p);
	printf("\n GPIO_ADDR =0x%x\n", REG32(p));
	
	int xValue=444;
	printf("\n %d \n", CUSTOM_MACRO(x, Value));
}



