#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x=434;
    int y=4334;
    const int *p; //p is pointer to const data
    p=&x;

    printf("\n *p=%d", *p);
    //*p=54;  //data cannot be changed  since data is const
    
    p=&y;
    printf("\n *p=%d", *p);

    int * const p2=&x; //p2 is  a constant pointer to data   
    printf("\n *p2=%d", *p2);
        
    //p2=&y;  //ptr address cannot be changed  since ptr address is const
    *p2 = 7878;
    printf("\n *p2=%d", *p2);

    const int * const p3=&x;  //p3 is  a constant pointer to const data
    
    printf("\n *p3=%d", *p3);
        
    //p3=&y;  //ptr address cannot be changed  since ptr address is const
    //*p3 = 7878;  // p3 data cannot be changed 
    printf("\n *p3=%d", *p3);

    int *p5=NULL;
//    *p5=45;
  //      printf("\n *p5=%d", *p5);

  const int **q;
  *q=p;
  //**q=433;
       printf("\n q =0x%x **q=%d", q, **q);
      
int *m=malloc(sizeof(int));
*m=434;
printf("\n before free m=0x%x   *m=%d", m, *m);
free(m);
printf("\nafter free  m=0x%x   *m=%d", m, *m);

int k=33;
int *n=&k;
++*n;

printf("\n n=0x%x  *n =%d", n, *n);

*++n;

printf("\n n=0x%x *n =%d", n,*n);

}
