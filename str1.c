#include<stdio.h>
#include<string.h>
int main()
{
    char Arr[20] = "Hello";
    char Brr[20];
    char Crr[20] = " World";
    
    int ret = 0;
    
    printf("Size of Arr is : %d\n",sizeof(Arr));    // 10
    
    printf("Length of arr is : %d\n",strlen(Arr));  // 5
    
    strcpy(Brr, Arr);
    
    printf("Contents of Brr : %s\n",Brr);
    
    ret = strcmp(Arr,Brr);
    
    if(ret == 0)
    {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are not equal\n");
    }
    
    strcat(Arr,Crr);
    
    printf("String after concatination is : %s\n",Arr);
    return 0;
}
