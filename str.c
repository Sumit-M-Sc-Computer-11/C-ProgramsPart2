
#include<stdio.h>

int main()
{
    char arr[] = "Hello";
    
    char brr[6] = "Hello";
    
    char crr[] = {'H','e','l','l','o','\0'};
    
    char *p = arr;
    
    while(*p != '\0')
    {
        printf("%c\n",*p);
        p++;
    }
    
    for(p = arr; *p != '\0'; p++)
    {
        printf("%c\n",*p);
    }
    
    return 0;
}

// H    e   l   l   o
