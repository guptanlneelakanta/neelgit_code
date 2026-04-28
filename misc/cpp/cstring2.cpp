#include <stdio.h>
#include <string.h>


int main() {
    const char str[] = "Tutorials.point";
    const char ch = '.';
    
    const char *ret = strchr(str, ch);

    if (ret != NULL)
        printf("String after |%c| is - |%s|\n", ch, ret);
    else
        printf("Character |%c| not found in string\n", ch);
    
    return 0;
}