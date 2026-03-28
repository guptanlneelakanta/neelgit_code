#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *str;
}test;

int main()
{
    test t1;
    t1.str = (char*)malloc(sizeof(char) * 30);
strcpy(t1.str, "hello welcome to shaalowcopy");
    test t2;

    t2=t1; //shallow copy
t2.str[0] = 'X';
    t2.str[1] = 'y';

    
    printf("\nafter shallow copy t1.str=%s,   \n t2.str=%s", t1.str, t2.str);
    
    
    //deepcopy
    strcpy(t1.str, "hello welcome to shaalowcopy");
    t2.str = (char*)malloc(sizeof(char) * 30);
    strcpy(t2.str, t1.str);   //deep copy
    
    t2.str[0] = 'X';
    t2.str[1] = 'y';

    printf("\nafter deep copy t1.str=%s,   \n t2.str=%s", t1.str, t2.str);

}