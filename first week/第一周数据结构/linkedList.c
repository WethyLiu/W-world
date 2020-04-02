#include "linkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) 
{
    *L=(LinkedList)malloc(sizeof(LNode));
    if(!(*L))return ERROR;
    (*L)->next=NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L)
{
    LinkedList p;
    while(*L!=NULL)
    {
        p=(*L)->next;
        free(*L);
        (*L)=p;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{
    if(p==NULL||q==NULL)return ERROR;
    q->next=p->next;
    p->next=q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p) 
{
    if(p==NULL&&p->next==NULL)return ERROR;
    LNode*q;
    q=p->next;
    p->next=p->next->next;
    q->next=NULL;
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L)
{
    LNode*q;
    q=L;
    while (q!=NULL)
    {
        printf("%d -> ",q->data);
        q=q->next;
    }
    printf("NULL\n");
    
}



/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList *L, ElemType e) 
{
    int i;
    LNode*q;
    q=*L;
    for(i=1;q!=NULL;q=q->next,i++)
    {
        if(q->data==e)
        {printf("第%d个结点出现数据%d\n",i,e);
        }
    }
    return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{
    if(!(*L)&&!(*L)->next)return ERROR;
    LinkedList head,p,next;
    head=(*L);
    p=(*L)->next;
    head->next=NULL;
    for(;p;)
    {
        next=p->next;
        p->next=head;
        head=p;
        p=next;
    }
    (*L)=head;
    return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
    LinkedList p,q;
    for(p=L,q=L;p==NULL;p=p->next->next,q=q->next)
    {
        if (p->data==q->data)
        {
            return SUCCESS;
        }
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
    LinkedList p,q,f;
    f=(LinkedList)malloc(sizeof(LNode));
    p=f;
    p->next=(*L);
    q=(*L);
    while (q!=NULL&&q->next!=NULL)
    {
        p->next=q->next;
        q->next=p->next->next;
        p->next->next=q;
        p=q;
        q=q->next;
    }
    (*L)=f->next;
    f->next=NULL;
    free(f);
    
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) 
{
    LinkedList fast,slow;
    fast=*L;
    slow=*L;
    for(;fast!=NULL&&fast->next!=NULL;fast=fast->next->next)
    {
        slow=slow->next;
    }
    return slow;
}

