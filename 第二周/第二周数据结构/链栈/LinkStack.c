#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


Status initLStack(LinkStack **s)//��ʼ��ջ
{
    if((*s)!=NULL)
    {
        printf("ջ�Ѵ��ڣ��޷���ʼ��\n");
        return ERROR;
    }
    (*s)=(LinkStack*)malloc(sizeof(LinkStack));
    if(*(s)==NULL)
    {
        printf("LinkStack malloc error\n");
        system("pause");
        return ERROR;
    }
    (*s)->top=NULL;
    (*s)->count=0;
    printf("��ʼ���ɹ�\n");
    return SUCCESS;    
}





Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    if(s->top==NULL)
    printf("��ǰջΪ��\n");
    else
    {
        printf("��ǰջ��Ϊ��\n");
    }
    return SUCCESS;
}



Status getTopLStack(LinkStack *s,ElemType e)//�õ�ջ��Ԫ��
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    if(s->top==NULL)
    {
        printf("ջ����Ԫ��\n");
        return ERROR;
    }
    e=s->top->data;
    printf("ջ��Ԫ��Ϊ%d",s->top->data);
    return SUCCESS;
}


Status clearLStack(LinkStack *s)//���ջ
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    if(s->top!=NULL)
    {
    LinkStackPtr p;
    p=s->top;
    for(s->top=p->next;s->top!=NULL;p=s->top)
    {
        p->next=NULL;
        free(p);
    }
    }
    s->count=0;
    printf("��ճɹ�\n");
    return SUCCESS;
}




Status destroyLStack(LinkStack **s)//����ջ
{
    if((*s)==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    LinkStackPtr p;
    if ((*s)->top!=NULL)
    {
        p=(*s)->top;
    for((*s)->top=p->next;(*s)->top!=NULL;p=(*s)->top)
    {
        p->next=NULL;
        free(p);
    }
    }
    if((*s)->top==NULL)
    {
        free(*s);
        (*s)=NULL;
    }
    printf("���ٳɹ�\n");
    return SUCCESS;
}


Status LStackLength(LinkStack *s,int length)    //�����zhan����
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    length = s->count;
    printf("��ջ����Ϊ��%d\n",length);
    return SUCCESS;
}


Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    LinkStackPtr p;
    p=(LinkStackPtr)malloc(sizeof(StackNode));
    if(p==NULL)
    {
        printf("StackNode malloc error\n");
        return ERROR;
    }
    p->data=data;
    p->next=s->top;
    s->top=p;
    s->count++;
    printf("��ջ�ɹ���\n");
    return SUCCESS;
}



Status popLStack(LinkStack *s,ElemType datas)   //��ջ
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    if(s->top == NULL) {printf("����ջ��ִ�У�\n"); return ERROR;}

    LinkStackPtr current;
    datas = s->top->data;
    current = s->top;
    s->top = s->top->next;
    free(current);
    s->count--;
    printf("��ջԪ��Ϊ��%d\n",datas);
    return SUCCESS;
}





Status printfLStack(LinkStack*s)
{
    if(s==NULL)
    {
        printf("ջδ��ʼ�����޷����д˲���\n");
        return ERROR;
    }
    LinkStackPtr p;
    p=s->top;
    for(;p!=NULL;p=p->next)
    printf(" %d ",p->data);
    return SUCCESS;
}