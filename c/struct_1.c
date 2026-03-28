#include<stdio.h>

typedef struct
{
    int aa:3;
    int b:3;
    int cc:2;
}t;

int main()
{
    t t1;
    t1.aa=5;
    t1.b=-9;
    t1.cc=3;
    printf("\n %d %d %d", t1.aa, t1.b, t1.cc);

    int m=-35;
    printf("\n m = %d ", m );

}

