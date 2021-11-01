#include<stdio.h>

void DisplayR(int iNo)
{
    if(iNo > 0)
    {
        printf("%d\n",iNo);
        iNo--;
        DisplayR(iNo);
    }
}

int main()
{
    int iValue = 0;
    printf("Enter number\n");
    scanf("%d",&iValue);
    
    DisplayR(iValue);   // DisplayR(3)
    
    printf("End of main\n");
    return 0;
}
