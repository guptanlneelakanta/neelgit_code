#include <stdio.h>

#pragma pack(1)

struct B
{
    char  c;
    int   i;
    char  d;
};

//#pragma pack()

int main()
{
    printf("Size = %lu\n", sizeof(struct B));
    return 0;
}
