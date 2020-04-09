#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"



SqStack* initStack(SqStack *p,int sizes)//��ʼ��ջ
{
    SqStack*s;
    s=p;
    if(sizes<=0)
    {
        printf("���������0����\n");
        system("pause");
        return NULL;
    }
    if(s!=NULL)
    {
        printf("ջ�Ѵ��ڣ��޷���ʼ��\n");
        system("pause");
        return s;
    }
    s=(SqStack*)malloc(sizeof(SqStack));
    if(s==NULL)
    {
        printf("SqStack malloc error\n");
        system("pause");
        return s;
    }
    s->elem=(int*)malloc(sizeof(int)*sizes);
    if(s->elem==NULL)
    {
        printf("SqStack's elem malloc error\n");
        free(s);
        s=NULL;
        system("pause");
        return s;
    }
    s->size=sizes;
    s->top=-1;
    return s;
}



Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }
    if (s->top==-1)
    {
        printf("ջΪ��\n");
    }
    if(s->top==s->size-1)
    {
        printf("ջ����\n");
    }
    else printf("ջ����%d��Ԫ��",s->top+1);
    return SUCCESS;        
}



Status getTopStack(SqStack *s,ElemType e) //�õ�ջ��Ԫ��
{
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }
    if (s->top==-1)
    {
        printf("ջΪ��\n");
        return ERROR;
    }
    e=s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack *s)//���ջ
{
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }    
    s->top=-1;
    return SUCCESS;
}


SqStack *destroyStack(SqStack *p)//����ջ
{
    SqStack *s;
    s=p;
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        system("pause");
        return NULL;
    }
    free(s->elem);
    s->elem=NULL;
    free(s);
    s=NULL;
    printf("����ջ�ɹ���\n");
    return NULL;
}


Status pushStack(SqStack *s,ElemType data)//��ջ
{
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }
    if(s->top==s->size-1)
    {
        printf("ջ��������֧�ָò���\n");
        return ERROR;
    }
    s->top++;
    (s->elem)[s->top]=data;
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType data)//��ջ
{
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }
    if(s->top==-1)
    {
        printf("ջΪ�գ���֧�ָò���\n");
        return ERROR;
    }
    data=(s->elem)[s->top];
    (s->top)--;
    return SUCCESS;
}



Status printStack(SqStack *s)
{
    int i=0;
    if(s==NULL)
    {
        printf("ջ�����ڣ���֧�ָò���\n");
        return ERROR;
    }
    if(s->top==-1)
    {
        printf("ջΪ�գ���֧�ָò���\n");
        return ERROR;
    }
    printf("Stack bottom ");
    for(;i<=s->top;i++)
    printf(" %d ",(s->elem)[i]);
    printf("  Stack top  \n");
    return SUCCESS;
    
}