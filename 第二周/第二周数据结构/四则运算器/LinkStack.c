#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
    s->count = 0;
    s->top = NULL;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
    if(s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

int getTopLStack(LinkStack *s)  //�õ�ջ��Ԫ��
{
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��
    {
        return ERROR;
    }
    return s->top->data;
}

Status clearLStack(LinkStack *s)   //���ջ
{
    LinkStackPtr pre;
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��
    {
        return ERROR;
    }
    pre = s->top;
    while(s->top)       //�ͷ���ջ�ڴ棬ֱ��ջ��
    {
        s->top = pre->next;
        free(pre);
        pre = s->top;
    }
    s->count = 0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //����ջ
{
    LinkStackPtr pre;
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��
    {
        s->count = -1;
        return ERROR;
    }
    pre = s->top;
    while(s->top)       //�ͷ���ջ�ڴ棬ֱ��ջ��
    {
        s->top = pre->next;
        free(pre);
        pre = s->top;
    }
    s->count = -1;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,ElemType *length)    //���ջ����
{
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��
    {
        (*length) = 0;
        return ERROR;
    }
    (*length) = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
    LinkStackPtr pre = (LinkStackPtr)malloc(sizeof(struct StackNode));
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��,���Ϊ����nextָ��NULL������ָ����һ��ջ��Ԫ��
    {
        pre->data = data;
        pre->next = NULL;
        s->top = pre;
    }
    else
    {
        pre->data = data;
        pre->next = s->top;
        s->top = pre;
    }
    s->count++;
    return SUCCESS;
}

int popLStack(LinkStack *s)   //��ջ
{
    int temp;
    LinkStackPtr pre;
    if(s->count == 0)  //�ж���ջ�Ƿ�Ϊ��
    {
        return 0;
    }
    pre = s->top;
    temp = s->top->data;
    s->top = s->top->next;
    s->count--;
    free(pre);
    return temp;
}


