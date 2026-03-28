#include<stdio.h>

void str_rev(char *str)
{ 
    char *end=str;    
    //char temp;
    while(*end != '\0')
    end++;
    end--;

    while(str<end)
    {
        //temp=*end;
        //*end= *str;
        //*str = temp;

        *end = *end ^ *str;
        *str= *str ^ *end;
        *end= *end ^ *str;
        
        end --;
        str++;
    }
}

//a= 101
//b =110
//a = a^b = 011
//b = b^a = 101
//a= b^a =  110

int main()
{
    char str1[] = "hello";
   str_rev(str1) ;
   printf("\n %s", str1);
}