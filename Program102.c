
#include<stdio.h>

void strncpyX(const char src[], char dest[], int value)
{
        if((src == NULL) || (dest == NULL) || (value <= 0))
        {
            return;
        }
        
        while((value>0) && (*src != '\0'))
        {
            *dest = *src;
            dest++;
            src++;
            value--;
        }
    *dest = '\0';
}


int main()
{
    char arr[20];
    char brr[20];
    int iNo = 0;

    printf("Enter String\n");
    scanf("%[^'\n']s",arr);

    printf("Enter number of elements to copy\n");
    scanf(" %d",&iNo);
    
    strncpyX(arr,brr,iNo);
    
    printf("String after copy is : %s\n",brr);
    return 0;
}

/*
 
                                                                Break chalu ahe
 
        Logic Building batch contents:
 
        Duration : 3.5 Months   (Thoda pudhe mage hou shakata)
        Tiiming : 6.30 PM to Till topic completes
 
        Days : Monday to Wednesday (For Data Structures 7 days in a week)
 
        C Programming : 50% of applications
        C++ Programming : 10% of applications
        Java Programming :  40 % of applications
        (% thoda pudhe mage hou shakata)
 
        Project :
        1 : C & C++ Native OS based (Native means awaghad)
        2 : Java based
 
        Note : Camera should be on from tomorrow.
 */


























