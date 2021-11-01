#include<stdio.h>

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
    printf("End of main\n");
    return 0;
}
// Output : *   *   *   *   End of main
// Contents of stack frame

// Memory for local variable
// Memmory for input argument
// Value of old EBP
// Address of next instruction






