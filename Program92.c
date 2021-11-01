#include<stdio.h>

void Display(char str[])
{
    int iCnt = 0;
    if(str == NULL)
    {return;}
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }
    str--;
    for(  ; iCnt > 0; iCnt--, str--)
    {
        printf("%c",*str);
    }
    printf("\n");
}

int main()
{
    char Arr[10];
    int iRet = 0;
    printf("Enter string\n");
    scanf("%[^'\n']s",Arr);
    Display(Arr);
    return 0;
}
