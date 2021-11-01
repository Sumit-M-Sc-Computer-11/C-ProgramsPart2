// HellO
// HELLO

#include<stdio.h>

void strcpyXX(char src[], char dest[])
{
    if(src == NULL || dest == NULL)
    {
        return;
    }
    while(*src != '\0')
    {
        if((*src >= 'a') && (*src <= 'z'))
        {
            *dest = *src -32;
        }
        else
        {
            *dest = *src;
        }
        src++;
        dest++;
    }
    *dest = '\0';
}
int main()
{
    char arr[20];
    char brr[20];
    
    printf("Enter string\n");
    scanf("%[^'\n']s",arr);
    
    strcpyXX(arr,brr);   // strcpyX(100,200)
    printf("Original string is : %s\n",arr);
    printf("After copy strinng is : %s\n",brr);
    
    return 0;
}
