#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE, **PPNODE;

void InsertNode(PPNODE Head, int iNo)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;
    
    if(*Head == NULL)    // Root node
    {
        *Head = newn;
    }
    else            // Tree contains atleast one node
    {
        while(1)
        {
            if(iNo > temp->data)    //  Data matha
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)   // Data lahan
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)  // data same
            {
                printf("Duplicate element\n");
                free(newn);
                break;
            }
        }
    }
}

void Inorder(PNODE Head)    // LDR                  //      21      11      51
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);      // L
        printf("%d\t",Head->data);  // D
        Inorder(Head->rchild);  // R
    }
}
void Postorder(PNODE Head)  // LRD
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);  // L
        Postorder(Head->rchild);  // R
        printf("%d\t",Head->data); // D
    }
}
void Preorder(PNODE Head)   // DLR
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data); // D
        Preorder(Head->lchild);  // L
        Preorder(Head->rchild);  // R
    }
}

void Count(PNODE Head, int *p)
{
    if(Head != NULL)
    {
        (*p)++;
        Count(Head->lchild,p);
        Count(Head->rchild,p);
    }
}

void CountLeaf(PNODE Head, int *p)
{
    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head -> rchild == NULL))
        {
            (*p)++;
        }
        CountLeaf(Head->lchild,p);
        CountLeaf(Head->rchild,p);
    }
}

void CountParent(PNODE Head, int *p)
{
    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head -> rchild != NULL))
        {
            (*p)++;
        }
        CountParent(Head->lchild,p);
        CountParent(Head->rchild,p);
    }
}

bool Search(PNODE Head, int iNo)
{
    if(Head != NULL)
    {
        if(iNo > Head->data)
        {
            return Search(Head->rchild,iNo);
        }
        else if(iNo < Head->data)
        {
            return Search(Head->lchild,iNo);
        }
        else if(iNo == Head->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    PNODE Root = NULL;
    bool bret = false;
    int iChoice = 1, iNo = 0, iRet = 0, i = 0;
    while(iChoice != 0)
    {
        printf("Enter your choice\n");
        printf("1 : Insert node\n");
        printf("2 : Display Inorder\n");
        printf("3 : Display Preorder\n");
        printf("4 : Display Postorder\n");
        printf("5 : Count nodes\n");
        printf("6 : Count leaf node\n");
        printf("7 : Count parent nodes\n");
        printf("8 : Search specific element\n");
        printf("0 : Terminate the appplication\n");
        
        scanf("%d",&iChoice);
        
        switch(iChoice)
        {
            case 1 :
                printf("Enter number\n");
                scanf("%d",&iNo);
                InsertNode(&Root,iNo);
                break;
                
            case 2 :
                printf("Inorder traversal\n");
                Inorder(Root);
                printf("\n");
                break;
                
            case 3:
                printf("Preorder traversal\n");
                Preorder(Root);
                printf("\n");
                break;
            
            case 4:
                printf("Postorder traversal\n");
                Postorder(Root);
                printf("\n");
                break;
                
            case 5:
                i = 0;
                Count(Root,&i);
                printf("Number of nodes are : %d\n",i);
                i = 0;
                break;
                
            case 6:
                i = 0;
                CountLeaf(Root,&i);
                printf("Number of leaf nodes are : %d\n",i);
                i = 0;
                break;
                    
            case 7:
                i = 0;
                CountParent(Root,&i);
                printf("Number of parent nodes are : %d\n",i);
                i = 0;
                break;
                
            case 8:
                printf("Enter element to search\n");
                scanf("%d",&iNo);
                bret = Search(Root,iNo);
                if(bret == true)
                {
                    printf("%d present in BST\n",iNo);
                }
                else
                {
                    printf("%d is not presnt in BST\n",iNo);
                }
                break;
                
            case 0:
                printf("Thank you for using appplication\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;
        } //End of switch
    }  // End of while
    return 0;
}   // End of main
