#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

bool CheckPerfectI(int iNo)
{
    int iSum = 0, iCnt = 1;
    while(iCnt<= iNo/2)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
        iCnt++;
    }
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CheckPerfectR(int iNo)
{
    static int iSum = 0, iCnt = 1;
    if(iCnt<= iNo/2)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
        iCnt++;
        CheckPerfectR(iNo);
    }
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iValue = 0;
    bool bRet;
    printf("Enter number\n");
    scanf("%d",&iValue);
    bRet = CheckPerfectR(iValue);
    if(bRet == true)
    {
        printf("It is perfect number\n");
    }
    else
    {
        printf("It is not perfect number\n");
    }
    return 0;
}
