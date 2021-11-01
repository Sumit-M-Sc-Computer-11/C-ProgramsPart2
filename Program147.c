#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(Temp->next ->next != NULL)
        {
            Temp = Temp -> next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void InsertAtPosition(PPNODE Head, int no, int iPos)
{
    int iSize = 0, i = 0;
    PNODE newn = NULL;
    PNODE Temp = *Head;
    
    iSize = Count(*Head);
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    if(iPos == 1)                   // First poistion
    {
        InsertFirst(Head,no);
    }
    else if(iPos == iSize+1)    // Last position
    {
        InsertLast(Head,no);
    }
    else        // In between fisrst and last position
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
}

void DeleteAtPosition(PPNODE Head, int iPos)
{
    int iSize = 0, i = 0;
    PNODE Temp = *Head;
    PNODE Target = NULL;
    
    iSize = Count(*Head);
    
    if((iPos < 1) || (iPos > iSize))      // Invalid position
    {
        return;
    }
    if(iPos == 1)                   // First poistion
    {
        DeleteFirst(Head);
    }
    else if(iPos == iSize)    // Last position
    {
        DeleteLast(Head);
    }
    else        // In between fisrst and last position
    {
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        Target = Temp -> next;
        
        Temp->next = Target -> next;
        free(Target);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0, iOption = 1, iValue = 0, iPos = 0;
    
    while(iOption != 0)
    {
        printf("\n____________________________________\n");
        printf("Enter your action on Linked list : \n");
        printf("1 : Insert node at first position\n");
        printf("2 : Insert node at last position\n");
        printf("3 : Insert node at given position\n");
        printf("4 : Delete first node\n");
        printf("5 : Delete last node\n");
        printf("6 : Delete node at given position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count number of nodes of linked list\n");
        printf("0 : Exit the application\n");
        scanf("%d",&iOption);
        printf("\n____________________________________\n");
        
        switch(iOption)
        {
            case 1 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertFirst(&First,iValue);
                break;
                
            case 2 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertLast(&First,iValue);
                break;
                
            case 3:
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                
                printf("Enter the position\n");
                scanf("%d",&iPos);
                InsertAtPosition(&First,iValue,iPos);
                break;

            case 4:
                DeleteFirst(&First);
                break;
                
            case 5 :
                DeleteLast(&First);
                break;
            
            case 6:
                    printf("Enter the position\n");
                    scanf("%d",&iPos);
                    DeleteAtPosition(&First,iPos);
                    break;
            
            case 7:
                printf("Nodes of linked list are : \n");
                Display(First);
                break;
                
            case 8 :
                iRet = Count(First);
                printf("Number of nodes are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank you for using Marvellous Linked list application \n");
                break;
                
            default:
                printf("Please enter valid option \n");
                break;
        } // End of switch
    } // End of while
    return 0;
} // End of main
































