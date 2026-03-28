#include<stdio.h>
int add(int a, int b)
{
    return a+b;
}

int mul(int a, int b)
{
    return a * b;
}

int main()
{
    int (*funptr[2])(int a, int b) = { add, mul};

    int res= funptr[1](4,5);
    printf("\n res= %d", res);

    res= funptr[0](4,5);
    printf("\n res= %d", res);

}

