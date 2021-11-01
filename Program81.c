#include<stdio.h>

int strlenX(char str[])
{
    int iCnt = 0;
    
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}




int main()
{
    char Arr[10];
    int iRet = 0;
    printf("Enter your name\n");
    scanf("%[^'\n']s",Arr);
    //fgets(Arr,10,stdin);        // Hello
  
    iRet = strlenX(Arr);   // Display(100)
    printf("String length is : %d\n",iRet);
    return 0;
}
