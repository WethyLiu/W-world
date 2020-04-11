#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

AQueue * InitAQueue(AQueue *Q)
{
    if(Q!=NULL)
    {
        printf("队列已已存在，无法执行此操作\n");
        return Q;
    }
    Q=(AQueue*)malloc(sizeof(AQueue));
    if(Q==NULL)
    {
        printf("AQueue malloc error\n");
        return NULL;
    }
    int i;
    for(i = 0; i < MAXQUEUE; i++)
    {
        Q->data[i] = (void *)malloc(21);
        Q->datatype[i]=0;
    }
	Q->front = Q->rear = -1;
    Q->length=0;
    printf("AQueue create success\n");
    return Q;
}



AQueue * DestoryAQueue(AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return NULL;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
    free (Q);
    Q=NULL;
    printf("队列销毁成功！\n");
    return NULL;
}




Status IsFullAQueue(const AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(Q->length==MAXQUEUE)
    {
        printf("the Queue is full\n");
        return TRUE;
    }
    else
        printf("the Queue isn't full\n");
    return FALSE; 
}


Status IsEmptyAQueue(const AQueue *Q)
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




Status GetHeadAQueue(AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==1)
	{
        printf("无法执行此操作\n");
		return FALSE;
	}
    printf("队首元素为：");
	APrint(Q->data[Q->front],Q->datatype[Q->front]);
    printf("\n");
    return TRUE;
}



int LengthAQueue(AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return Q->length; 
}



Status EnAQueue(AQueue *Q, void *data,int a)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsFullAQueue(Q)==1) 
	{
        printf("无法执行此操作！\n");
        return FALSE;
    }	
	Q->rear = (Q->rear+1) % MAXQUEUE;
    if(Q->front==-1)
        Q->front=0;
	memcpy(Q->data[Q->rear],data, 20);
    Q->datatype[Q->rear]=a;
    Q->length++;
	return TRUE;
}




Status DeAQueue(AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==1)
    {
        printf("无法执行此操作\n");
        return FALSE;
	}
    printf("出队元素为：");
    APrint(Q->data[Q->front],Q->datatype[Q->front]);
    printf("\n");
    Q->datatype[Q->front]=0;
    Q->front = (Q->front+1)%MAXQUEUE;
    Q->length--;
    if (Q->length==0)
    {
        Q->front=-1;
        Q->rear=-1;
    }
    printf("出队成功\n");
    return TRUE;
}	




void ClearAQueue(AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
    if (IsEmptyAQueue(Q)==1)
    {
        printf("无法执行此操作\n");
        return;
	}
    Q->length=0;
    Q->front=-1;
    Q->rear=-1;
    for(int i=0;i<MAXQUEUE;i++)
        Q->datatype[i]=0;
}




Status TraverseAQueue(const AQueue *Q)
{
    if(Q== NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==1)
    {
		printf("无法执行该操作\n");
        return FALSE;
    }
	int i = 0;
    while (i < Q->length)
    {	
        APrint(Q->data[Q->front+i], Q->datatype[Q->front+i]);
        i++;
	}
    printf("\n");
    return TRUE;
}



void APrint(void *q,int a)
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