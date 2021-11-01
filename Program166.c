#include<stdio.h>

void DisplayFactorI(int iNo)
{
    int iCnt = 1;
    
    while(iCnt <= iNo/2)
    {
        if(iNo % iCnt == 0)
        {
                printf("%d\t",iCnt);
        }
        iCnt++;
    }
}

void DisplayFactorR(int iNo)
{
    static int iCnt = 1;
    if(iCnt <= iNo/2)
    {
        if(iNo % iCnt == 0)
        {
            printf("%d\t",iCnt);
        }
        iCnt++;
        DisplayFactorR(iNo);
    }
}

int main()
{
    int iValue = 0, iRet = 0;
    printf("Enter number\n");
    scanf("%d",&iValue);
    
    DisplayFactorR(iValue);
    
    return 0;
}
