#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int fun(int *a, int *b)
{
	return abs(*a-*b);
}

struct  __attribute__((packed)) data {
    uint8_t a;
    uint16_t b;
};

struct __attribute__((packed)) data2 {
	uint16_t d;
	uint64_t a;
	uint16_t b;
	uint16_t c;
};

struct data3{
	int16_t d : 3;
	uint64_t a : 4;
	uint16_t b : 5;
	uint16_t c : 6;
};


int main()
{
	short int num;
	unsigned int num2;

	int a=4;
	int b=5;

	int res= fun(&a, &b);
	printf("\n res a-b = %d\n", res);

	struct data d1;
	printf("\n d1 size = %lu\n", sizeof(d1));

	struct data2 d2;
	printf("\n d2 size = %lu\n", sizeof(d2));

	struct data3 d3;
	d3.a = 115;
	d3.b = 131;
	d3.c = 163;	
	d3.d = 5;

	printf("\n d3.a  = %d\n", d3.a);
	printf("\n d3.b  = %d\n", d3.b);
	printf("\n d3.c  = %d\n", d3.c);
	printf("\n d3.d  = %d\n", d3.d);

}




