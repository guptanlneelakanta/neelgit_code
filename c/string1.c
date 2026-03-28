#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   char str1[30] ="welcome";
   char str2[30] ="hello";

   strcpy(str1,str2);
   printf("\n1. str1 =%s,   \n str2=%s", str1, str2);
   strcat(str1,str2);
   printf("\n2. str1 =%s,   \n str2=%s", str1, str2);
   int num = strcmp(str1,str2);
   printf("\n3. num =%d", num);
strcpy(str2,str1);
   num = strcmp(str1,str2);
   printf("\n3. num =%d", num);

   char *ch = strchr(str1,'l');
    printf("\n4. str1[0] = 0x%x  ch =0x%x   ch=%c", &str1[0], ch, *ch);

   printf("\nstr1 =%s,   \n str2=%s", str1, str2);

   char str5[]="test";
printf("\n sizeof(str5) = %d", sizeof(str5) );
printf("\n strlen(str5) = %d", strlen(str5) );
      printf("\nstr5[35] =%c ", str5[35]); //undefined behavior
      
}