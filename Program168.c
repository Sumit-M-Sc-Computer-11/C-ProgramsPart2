#include<stdio.h>
#include<stdlib.h>

int SumI(int Arr[], int iSize)
{
    int iSum = 0, iCnt = 0;
    while(iCnt < iSize)
    {
        iSum = iSum + Arr[iCnt];
        iCnt++;
    }
    return iSum;
}
int SumR(int Arr[], int iSize)
{
    static int iSum = 0;
    static int iCnt = 0;
    if(iCnt < iSize)
    {
        iSum = iSum + Arr[iCnt];
        iCnt++;
        SumR(Arr,iSize);
    }
    return iSum;
}

int main()
{
    int *p = NULL;
    int iRet = 0, iValue = 0, iCnt = 0;
    
    printf("Enter number of elements\n");
    scanf("%d",&iValue);
    p = (int *)malloc(sizeof(int) * iValue);
    printf("Enter the elements\n");
    while(iCnt < iValue)
    {
        scanf("%d",&p[iCnt]);
        iCnt++;
    }
    iRet = SumR(p,iValue);
    printf("Addition is : %d\n",iRet);
    free(p);
    return 0;
}
