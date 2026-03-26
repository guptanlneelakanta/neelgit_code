#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void revstr(char *str1)
{
    int i=0;
    printf("\n str1=%s", str1);
    int len= strlen(str1);
    printf("\n strlen str1=%d", len);
    char *s2=malloc(len);

    for(i=0; i<len; i++)
    *(s2+i) = *(str1+len-1-i);

    *(s2+i) =0;
    printf("\n s2=%s", s2);
    str1 = s2;
    printf("\n in fun str1=%s", str1);
}

void revstr2(char *str)
{
    char *end=str;
    char temp;

    while(*end)
    end++;

    end--;
    while(str<end)
    {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
    printf("\n in revstr2 str =%s",str);
}

void reverse3(char *str)
{
    char *end = str;
    char temp;

    while (*end)
        end++;

    end--;

    while (str < end)
    {
        temp = *str;
        *str = *end;
        *end = temp;

        str++;
        end--;
    }
}
int main()
{
    char s1[]="welcome";
    printf("\n s1=%s", s1);

    //revstr(s1);
    //printf("\n s1=%s", s1);

   // revstr2(s1);
   // printf("\nrevstr2  s1=%s", s1);

    reverse3(s1);
    printf("\nreverse3  s1=%s", s1);
}