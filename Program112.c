#include<stdio.h>
#include<stdbool.h>
/*
                   iNo         0   1   0   1   0   1   1   0
                   iMask      0   1   0   1   0  1   0   0             &
                        __________________________
                iResult       0  1    0   1   0   1   0   0
*/
        
bool CheckBit(unsigned int iNo, int iPos)
{
    unsigned int iMask = 0X00000001;
    unsigned int iResult = 0;
    if((iPos < 1) || (iPos > 32))
    {   return false;}
    iMask = iMask << (iPos -1);
    
    iResult = iNo & iMask;
    if(iResult == iMask)
    {   return true;    }
    else
    {   return false;   }
}
int main()
{
    unsigned int iValue = 0,iPos = 0;
    bool bRet;
    printf("Enter number\n");
    scanf("%u",&iValue);
    printf("Enter position\n");
    scanf("%d",&iPos);
    bRet = CheckBit(iValue,iPos);
    if(bRet == true)
    {   printf("Bit is on\n");}
    else
    {   printf("Bit is off\n"); }
    return 0;
}





































