#include<stdio.h>

void DisplayI()
{
    int i = 0;  // Local variable
    
    //      1          2       3
    for(i = 1; i <= 4; i++)
    {
        printf("*\n");  // 4
    }
}

void DisplayR()
{
    static int i = 1;          // 1
    if(i<= 4)           // 2
    {
        printf("*\n");  // 4
        i++;                // 3
        DisplayR();     // Recursive call
    }
}

int main()
{
    DisplayR();
    return 0;
}
