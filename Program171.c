/*
    iRow = 4
    iCol = 3
    *   *   *
    *   *   *
    *   *   *
    *   *   *
 */

#include<stdio.h>

void DisplayI(int iRow, int iCol)
{
    int i = 1, j = 1;
    while(i <= iRow)
    {
        j = 1;
        while (j <= iCol )
        {
            printf("*\t");
            j++;
        }
        i++;
        printf("\n");
    }
}
int main()
{
    int iValue1 = 0, iValue2 = 0;

    printf("Enter number of rows\n");
    scanf("%d",&iValue1);
    printf("Enter number of columns\n");
    scanf("%d",&iValue2);
    
    DisplayI(iValue1, iValue2);
    return 0;
}
