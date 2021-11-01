#include<stdio.h>

void Display(char str[])
{
    printf("Charcters from string are\n");
    
    while(*str != '\0')
    {
        printf("%c\n",*str);
        str++;
    }
}





int main()
{
    char Arr[10];
    
    printf("Enter your name\n");
    fgets(Arr,10,stdin);        // Hello
  
    Display(Arr);   // Display(100)
    
    return 0;
}
