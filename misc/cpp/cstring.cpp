#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    char s1[10] ="hello";
    char s2[10] ="world123";

    const char *s3 ="world123";

    cout<<strlen(s1)<<endl;
    int res=strcmp(s1,s2);
    cout<<"\nres = "<<res<<endl;

    strcat(s1,s2);
    cout<<"\ns1 = "<<s1<<endl;

    cout<<"\nstrlen(s1) = "<<strlen(s1)<<endl;

    //char * res1 = strchr(s3,'w');
    //cout<<"\nw location = "<<res<<endl;

    const char str[] = "Tutorialspoint";
    // "ch" is search string
    const char ch = '.';

 const   char *ret = strchr(str, ch);
   // printf("String after |%c| is - |%s|\n", ch, ret);

}
