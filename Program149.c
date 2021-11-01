#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;              // +
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // +
    
    if(*Head == NULL)   // Linked list is empty
    {
        *Head = newn;
    }
    else                        // Linked list contains atleast one node
    {
        newn ->next = *Head;
        (*Head) -> prev = newn;         // +
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // +
    
    if(NULL == *Head)   // Linked list is empty
    {
        *Head = newn;
    }
    else                        // Linked list contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newn;
        newn -> prev = temp;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|<=>",Head -> data);
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
        if(*Head == NULL)               // Empty LL
        {
            return;
        }
        else if ((*Head) -> next == NULL)   // Single node
        {
            free(*Head);
            *Head = NULL;
        }
        else        // More than one node
        {
            *Head = (*Head) ->next;
            free((*Head) -> prev);          // +
            (*Head) -> prev = NULL;        // +
        }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
        if(*Head == NULL)               // Empty LL
        {
            return;
        }
        else if ((*Head) -> next == NULL)   // Single node
        {
            free(*Head);
            *Head = NULL;
        }
        else        // More than one node
        {
            while(temp->next->next != NULL)
            {
                temp = temp -> next;
            }
            free(temp->next);
            temp->next = NULL;
        }
}

void InsertAtPos(PPNODE Head , int No, int iPos)
{
    int iSize = 0, i = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;

    iSize = Count (*Head);
    
    if((iPos < 1)||(iPos > iSize +1))
    {
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(Head , No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;
        
        for(i= 1; i< iPos -1 ; i++)
        {
            temp = temp -> next;
        }
        newn->next = temp -> next;
        temp->next->prev = newn;        // +
        temp -> next = newn;
        newn->prev = temp;                  // +
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = 0, i= 0;
    PNODE temp = *Head;
    iSize = Count(*Head);
    
    if((iPos < 1) || (iPos > iSize))
    {
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        for(i =1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE First = NULL;
    int iOption = 1, iValue = 0, iRet = 0, iPos = 0;
    
    while(iOption != 0)
    {
        printf("\n********************************\n");
        printf("Please select the option\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at last position\n");
        printf("3 : Insert the node at given position\n");
        printf("4 : Delete the fisrt node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at given position \n");
        printf("7 : Display the contents of linked list \n");
        printf("8 : Count the nodes of linked list \n");
        printf("0 : Exit the application\n");
        scanf("%d",&iOption);
        printf("********************************\n");
        
        switch(iOption)
        {
            case 1:
                printf("Enter data to insert\n");
                scanf("%d",&iValue);
                InsertFirst(&First,iValue);
                break;
                
            case 2:
                printf("Enter data to insert\n");
                scanf("%d",&iValue);
                InsertLast(&First,iValue);
                break;
                
            case 3:
                printf("Enter data to insert\n");
                scanf("%d",&iValue);
                printf("Enter position\n");
                scanf("%d",&iPos);
                InsertAtPos(&First,iValue,iPos);
                break;
                
            case 4:
                DeleteFirst(&First);
                break;
                    
            case 5:
                DeleteLast(&First);
                break;
                    
            case 6:
                printf("Enter position\n");
                scanf("%d",&iPos);
                DeleteAtPos(&First,iPos);
                break;
                    
            case 7:
                printf("Contents of linked list are \n");
                Display(First);
                break;
                    
            case 8:
                iRet = Count(First);
                printf("Number of nodes are : %d\n",iRet);
                break;
                    
            case 0:
                printf("Thank you for using Marvellous Linked list\n");
                break;
                    
            default:
                printf("Please enter proper option\n");
                break;
        }
    }
    
    return 0;
}   // End of main



















/*
while(temp != NULL)                     // 1            temp->NULL              Display & Count
{
    temp = temp -> next;
}

while(temp->next != NULL)           // 2            temp->400               InsertLast
{
    temp = temp -> next;
}

while(temp->next->next != NULL) // 3             temp-> 300             DeleteLast
{
    temp = temp -> next;
}
*/

