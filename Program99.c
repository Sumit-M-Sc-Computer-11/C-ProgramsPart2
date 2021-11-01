#include<stdio.h>

void strcatX(const char src[], char dest[])
{
    if(src == NULL || dest == NULL)
    {
        return;
    }
    while(*dest != '\0')
    {
        dest++;
    }
    while(*src!= '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
int main()
{
    char arr[20];
    char brr[20];
    
    printf("Enter first string\n");
    scanf("%[^'\n']s",arr);   //     Demo
    printf("Enter second string\n");    // Hello
    scanf(" %[^'\n']s",brr);
    strcatX(arr,brr);
    printf("After concat strinng is : %s\n",brr); // HelloDemo
    
    return 0;
}
