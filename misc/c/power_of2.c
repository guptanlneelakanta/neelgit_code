#include<stdio.h>


#define MIN(n1,n2) ( (n1) <= (n2) ? (n1) : (n2));

int main()
{
	int num;

	printf("\n enter number\n");
	scanf("%d", &num);
	if(num && ((num & num-1) == 0))
		printf("\n num is power of 2");
	else
		printf("\n num is not power of 2\n ");
		
	int i=0;
	while(100-i)	
	printf("%d ", ++i);
	
	int m = MIN(5,6);
	printf("\n m=%d\n", m);
		
}


