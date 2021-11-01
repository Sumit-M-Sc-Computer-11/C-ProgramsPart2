
/*
    1. Create staic character array in main function
    2. Accept the string into that array
    3. Pass that string to the function
    4. Function will perform the operation on that string
 */

#include<stdio.h>

int main()
{
    char Arr[40];
    
    printf("Enter your name\n");
    scanf("%[^'\n']s",Arr);
    
    //fgets(Arr,40,stdin);  // fgets(Kashat, kiti, kuthun)
    //gets(Arr);
    //scanf("%s",Arr);
    
    printf("Your name is : %s\n",Arr);
    
    return 0;
}
