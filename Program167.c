#include<stdio.h>

int StrlenI(char str[])
{
    int iCnt = 0;
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}

int StrlenR(char str[])
{
    static int iCnt = 0;
    if(*str != '\0')
    {
        iCnt++;
        str++;
        StrlenR(str);
    }
    return iCnt;
}

int main()
{
    char arr[30] = {'\0'};
    int iRet = 0;
    printf("Enter string\n");
    scanf(" %[^'\n']s",arr);
    
    iRet = StrlenR(arr);
    
    printf("String length is : %d\n",iRet);
    return 0;
}
