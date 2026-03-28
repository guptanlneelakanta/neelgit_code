#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void  reverse(char *s1)
{
    int i=0,j=strlen(s1)-1;
    char temp;
    while(i<j)
    {
        printf("\n1. i=%d. j=%d", i,j);
        temp=s1[i];
        s1[i++] = s1[j];
        s1[j--] = temp;
        printf("\n2. i=%d. j=%d", i,j);
    }
    
}

void  reverse2(char *s1)
{
    char *end=s1;
    while(*end != '\0')
    end++;
    end--;
    
    while(s1 < end)
    {
        *s1 ^= *end;
        *end ^=*s1;
        *s1 ^= *end;
        s1++;
        end--;        
    }    
}

void reverse_string3(char *s) {
    char *e = s + strlen(s) - 1;
    while (s < e) {
        *s ^= *e;
        *e ^= *s;
        *s ^= *e;
        s++;
        e--;
    }
}

int main()
{
   char str1[30] ="12345";
   char str2[30] ="hello";

   int num = atoi(str1);
   printf("\n num=%d", num);
   reverse(str2);
   printf("\n str2 = %s", str2);
         
   char str3[] ="welcome";
   reverse_string3(str3) ;
   printf("\nreverse_string3 str3 = %s", str3);

   char str4[] ="wonder";
   reverse2(str4) ;
   printf("\nreverse2 str4 = %s", str4);
}