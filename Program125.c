#include<stdio.h>
#include<stdlib.h>
int Addition(int Arr[], int iSize)
{
    int i = 0, iSum = 0;
    if((Arr == NULL) || (iSize <= 0))
    {return 0;}
    for(i = 0 ; i <iSize;i++)
    {
        iSum = iSum + Arr[i];
    }
    return iSum;
}
int main()
{
    int *Arr = NULL;
    int iSize = 0, i = 0,iRet = 0;
    printf("Enter number of elements\n");
    scanf("%d",&iSize);
    Arr = (int *)malloc(iSize * sizeof(int));
    printf("Enter the elements\n");
    for(i = 0; i < iSize; i++)
    {
        scanf("%d",&Arr[i]);
    }
    iRet = Addition(Arr,iSize);
    printf("Addition is : %d\n",iRet);
    free(Arr);
    return 0;
}












