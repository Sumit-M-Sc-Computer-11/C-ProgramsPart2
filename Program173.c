/*
    iRow = 4
    iCol = 3
    *   *   *
    *   *   *
    *   *   *
    *   *   *
 */

#include<stdio.h>

void Display(int iCol)              // Display / travel columns
{
    static int j = 1;
    if(j <= iCol )
    {
        printf("*\t");
        j++;
        Display(iCol);      // Recursive call
    }
    j = 1;
}
void DisplayR(int iRow, int iCol)   // Display / travel rows
{
    static int i = 1;
    if(i <= iRow)
    {
        Display(iCol);      // Call to travel columns
        i++;
        printf("\n");
        DisplayR(iRow, iCol);   // Recursive call
    }
}
int main()
{
    int iValue1 = 0, iValue2 = 0;
    printf("Enter number of rows\n");
    scanf("%d",&iValue1);
    printf("Enter number of columns\n");
    scanf("%d",&iValue2);
    DisplayR(iValue1, iValue2);
    return 0;
}
