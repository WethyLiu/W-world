#include"LQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


LQueue* InitLQueue(LQueue *Q)
{
    if(Q!=NULL)
    {
        printf("队列已已存在，无法执行此操作\n");
        return Q;
    }
    Q=(LQueue*)malloc(sizeof(LQueue));
    if(Q==NULL)
    {
        printf("LQueue malloc error\n");
        return NULL;
    }  
    Q->length=0;
    Q->front=NULL;
    Q->rear=NULL;
    printf("create LQueue success!\n");
    return Q;
}


LQueue* DestoryLQueue(LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return NULL;
    }
    Node*p;
    for(;Q->front!=NULL;Q->front=p)
    {
        free(Q->front->data);
        p=Q->front->next;
        free(Q->front);
    }
    Q->rear=NULL;
    free(Q);
    printf("销毁队列成功\n");
    return NULL;
}


Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(Q->length==0)
    {
        printf("the Queue is empty\n");
        return TRUE;
    }
    else
        printf("the Queue isn't empty\n");
    return FALSE;
    
}


Status GetHeadLQueue(LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)==1)
	{
        printf("无法执行此操作\n");
		return FALSE;
	}
    printf("队首元素为：");
	LPrint(Q->front->data,Q->front->datatype);
    printf("\n");
    return TRUE;
}


int LengthLQueue(LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return Q->length;
}


Status EnLQueue(LQueue *Q, void *data,int a)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }	
    Node*p;
    p=(Node*)malloc(sizeof(Node));
    p->data=(void*)malloc(21);
    memcpy(p->data,data,20);
    p->datatype=a;
	if(Q->front==NULL)
    Q->front=p;
    if(Q->rear!=NULL)
    Q->rear->next=p;
    Q->rear=p;
    Q->length++;
    printf("入队成功！\n");
    return TRUE;
}


Status DeLQueue(LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)==1)
	{
        printf("无法执行此操作\n");
		return FALSE;
	}
    Node*p;
    p=Q->front;
    printf("出队元素为：");
	LPrint(Q->front->data,Q->front->datatype);
    printf("\n");
    Q->front=p->next;
    if(Q->front==NULL)
    Q->rear=NULL;
    free(p);
    Q->length--;
    printf("出队成功\n");
    printf("\n");
    return TRUE;
}


void ClearLQueue(LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
    if (IsEmptyLQueue(Q)==1)
	{
        printf("无法执行此操作\n");
		return;
	}
    Node*p,*q;
    Q->rear=NULL;
    p=Q->front;
    Q->front=NULL;
    while (NULL != p) 
    {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
    Q->length=0;
    printf("清空成功！\n");
    return ;
}


Status TraverseLQueue(const LQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)==1)
    {
		printf("无法执行该操作\n");
        return FALSE;
    }
	int i = 0;
    Node*p;
    p=Q->front;
    while (i < Q->length)
    {	
        LPrint(p->data,p->datatype);
        p=p->next;
        i++;
	}
    printf("\n");
    return TRUE;
}


void LPrint(void *q,int a)
{
    if(a == 3)
            printf("--> %.2lf", *(double*)q);
        if(a == 2)
            printf("--> %c", *(char*)q);
        if(a == 1)
            printf("--> %d ", *(int*)q);
        if(a == 4)
        {
            char a[20];
            memcpy(a,q,20);
            printf("--> %s ",(char*)a);
        }
}