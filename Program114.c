#include<stdio.h>
#include<stdbool.h>
/*
                   iNo         0   1   0   1   0   1   1   0
                   iMask      0   1   0   1   0  1   0   0             &
                        __________________________
                iResult       0  1    0   1   0   1   0   0
*/
        
bool CheckBit(unsigned int iNo, int iPos1, int iPos2)
{
    unsigned int iMask1 = 0X00000001, iMask2 = 0X00000001, iMask = 0X00000000;
    unsigned int iResult = 0;
    if((iPos1 < 1) || (iPos1 > 32) || (iPos2 < 1) || (iPos2 > 32))
    {   return false;}
    iMask1 = iMask1 << (iPos1 -1);
    iMask2 = iMask2 << (iPos2 -1);
    iMask = iMask1 | iMask2;
    iResult = iNo & iMask;
    if(iResult == iMask)
    {return true;}
    else
    {return false;}
}
int main()
{
    unsigned int iValue = 0,iPos1 = 0,iPos2 = 0;
    bool bRet;
    printf("Enter number\n");
    scanf("%u",&iValue);
    printf("Enter first position\n");
    scanf("%d",&iPos1);
    printf("Enter second position\n");
    scanf("%d",&iPos2);
    bRet = CheckBit(iValue,iPos1,iPos2);
    if(bRet == true)
    {printf("Bits are on\n");}
    else
    {printf("Bits are off\n");}
    return 0;
}





































