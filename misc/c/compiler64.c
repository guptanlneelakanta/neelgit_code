#include<stdio.h>
struct s1{
    int a:12;
    int c: 32;
    long int b: 4;
};
#pragma pack(1)
struct s2{
    int a:12;
    int c: 32;
    long int b: 4;
};



int main()
{
    int a;
    printf("long size =%zu \n ", sizeof(long));
    
    struct s1 ss;
    printf("struct size =%zu \n ", sizeof(ss));

    struct s2 ss2;
    printf("struct size 22 =%zu \n ", sizeof(ss2));

    return 0;
}

