#include<stdio.h>

#define setbit(reg, n) reg=(reg | (1<<n))
#define resetbit(reg, n) reg=(reg & (~(1<<n)))
#define togglebit(reg, n) reg=(reg ^ (1<<n))

int main()
{
    int reg=4;

    setbit(reg, 1 );
    printf("\n reg = %d",reg);

    resetbit(reg, 1 );
    printf("\n reg = %d",reg);

    togglebit(reg, 1 );
    printf("\n reg = %d",reg);

    togglebit(reg, 1 );
    printf("\n reg = %d",reg);

}