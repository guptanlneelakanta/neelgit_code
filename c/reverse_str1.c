#include<stdio.h>

int main()
{
    char str[] ="hello";
    char str2[6];
    int siz =sizeof(str);
    printf("\n siz=%d",siz);
    int i;
    for( i=1; i<siz; i++)
    {
        str2[i-1] = str[siz-1-i];
    }
    str2[siz-1]='\0';
    printf("\n %s",str2);
}