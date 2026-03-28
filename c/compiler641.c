#include<malloc.h>
#include<stdio.h>

struct s1{
    int a: 23;
  //  long int  m:44;
    int c : 4;
    //long int  n:34;
};
int main()
{
    struct s1 ss;
    int *p=malloc(sizeof (int));
    printf("\n hello \n");

    printf("\n p = %d\n", sizeof(p) );
    printf("\n p = %d\n", sizeof(p) );
    printf("\n ss = %d\n", sizeof(ss));
    printf("\n long = %zu\n", sizeof(long ));

}