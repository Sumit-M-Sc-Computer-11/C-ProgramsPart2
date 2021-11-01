#include<stdio.h>

void Display(char str[])
{
    int iCnt = 0;
    printf("Charcters from string are\n");
    
    while(str[iCnt] != '\0')
    {
        printf("%c\n",str[iCnt]);
        iCnt++;
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
