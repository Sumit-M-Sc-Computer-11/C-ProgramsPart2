// Addition of all digits of number

#include<stdio.h>

int SumDigitR(int iNo)
{
    static int iSum = 0;
    if(iNo != 0)
    {
        iSum = iSum + (iNo % 10);
        iNo = iNo / 10;
        SumDigitR(iNo);
    }
    return iSum;
}

int SumDigitI(int iNo)
{
    int iSum = 0;
    while(iNo != 0)
    {
        iSum = iSum + (iNo % 10);
        iNo = iNo / 10;
    }
    return iSum;
}

int main()
{
    int iValue = 0, iRet = 0;
    printf("Enter number\n");
    scanf("%d",&iValue);
    
    iRet = SumDigitR(iValue);
    printf("Addition of digits is : %d\n",iRet);
    
    return 0;
}
