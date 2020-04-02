#include "duLinkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


/**
 *  @name        : Result InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Result
 *  @notice      : None
 */
Result InitList_DuL(DuLinkedList *L) 
{
    *L=(DuLinkedList)malloc(sizeof(DuLNode));
    if(*L==NULL)return error;
    (*L)->next=NULL;
    (*L)->prior=NULL;
    return success;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : Result
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
    DuLNode*p;
    while (*L!=NULL)
    {
        p=(*L)->next;
        free(*L);
        *L=p;
        if(p!=NULL)p->prior=NULL;
    } 
}

/**
 *  @name        : Result InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : Result
 *  @notice      : None
 */
Result InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    if(p==NULL||q==NULL)return error;
    if(p->prior!=NULL)
    {
    p->prior->next=q;
    q->next=p;
    q->prior=p->prior;
    p->prior=q;
    return success;
    }
    else
    {
        p->prior=q;
        q->next=p;
        return  success;
    }
    
}

/**
 *  @name        : Result InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Result
 *  @notice      : None
 */
Result InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
    if(p==NULL||q==NULL)return error;
    if(p->next!=NULL)
    {
    p->next->prior=q;
    q->prior=p;
    q->next=p->next;
    p->next=q;
    return success;
    }
    else
    {
        p->next=q;
        q->prior=p;
        return success;
    }
    
}

/**
 *  @name        : Result DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Result
 *  @notice      : None
 */
Result DeleteList_DuL(DuLNode *p) 
{
    if(p==NULL&&p->next==NULL)return error;
    DuLNode*q;
    q=p->next;
    p->next=p->next->next;
    p->next->prior=p;
    q->next=NULL;
    q->prior=NULL;
    free(q);
    return success;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Result
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L)
{
    DuLNode*q;
    q=L;
    printf("NULL <-");
    while (q!=NULL)
    {
        printf("%d <-> ",q->data);
        q=q->next;
    }
    printf("NULL\n");
    
}

