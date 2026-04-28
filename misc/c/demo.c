#include<stdio.h>

void demo(void){
    unsigned int x = 10 ;
    int y =-40;
    printf("\n x+y=%d\n", x+y);
    
    if(x+y > 10) {
        printf("\nGreater than 10\n");
    } else {
        printf("\n Less than or equals 10\n");
    }
    
}

int main()
{

	demo();
	
	int num1=10, num2=20;
	num1^=num2^=num1^=num2;
	
	printf("\n num1=%d, num2=%d\n", num1, num2);

	num1=num1 ^num2	;
	num2=num2 ^num1	;

	num1=num1 ^num2	;

	printf("\n num1=%d, num2=%d\n", num1, num2);

}


