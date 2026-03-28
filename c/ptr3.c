#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m[]={33, 45,66,77};
    int  *p=m;
//p[1] = 36;
//p[2] = 136;
//p[3] = 236;
    ++*p;
    printf("\n1. p=0x%x, *P=%d", p, *p);
    *p++;
    printf("\n2. p=0x%x, *P=%d", p, *p);
    *++p;
    printf("\n3. p=0x%x, *P=%d", p, *p);

}

