#include<stdio.h>
#include<stdbool.h>
/*
                   iNo         0   1   0   1   0   1   1   0
                   iMask      0   1   0   1   0  1   0   0             &
                        __________________________
                iResult       0  1    0   1   0   1   0   0
*/
        
bool CheckBit(unsigned int iNo)
{
    unsigned int iMask = 0X00000054;  //0000    0000       0000     0000        0000    0000        0101        0100
    unsigned int iResult = 0;
    iResult = iNo & iMask;
    if(iResult == iMask)
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
    unsigned int iValue = 0;
    bool bRet;
    
    printf("Enter number\n");
    scanf("%u",&iValue);
    
    bRet = CheckBit(iValue);
    
    if(bRet == true)
    {
        printf("3,5,7 bits is on\n");
    }
    else
    {
        printf("Bits are off\n");
    }
    return 0;
}





































