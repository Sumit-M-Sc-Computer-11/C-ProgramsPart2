#include<stdio.h>
#include<stdbool.h>

/*
                    iPos = 4
 
 Input                   1       0       1       0       1       1       0       0
                           1        1       1       1       0       1       1       1               &
 ______________________________________________________
 
Output                 1       0       1       0       0       1       0       0
 
  */
unsigned int OffBit(unsigned int iNo, int iPos)
{
    unsigned int iMask = 0X00000001;
    unsigned int iResult = 0;
    if((iPos < 1) || (iPos > 32))
    {   return 0;}
    
    iMask = iMask << (iPos-1);
    
    iMask = ~iMask;
    
    iResult = iNo & iMask;
    return iResult;
}

int main()
{
    unsigned int iValue = 0,iPos = 0, iRet = 0;
    printf("Enter number\n");
    scanf("%u",&iValue);
    printf("Enter position\n");
    scanf("%d",&iPos);
    
    iRet = OffBit(iValue,iPos);
    
    printf("New number is : %u\n",iRet);
    return 0;
}





































