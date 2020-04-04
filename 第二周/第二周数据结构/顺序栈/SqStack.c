#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"



SqStack* initStack(SqStack *p,int sizes)//初始化栈
{
    SqStack*s;
    s=p;
    if(sizes<=0)
    {
        printf("请输入大于0的数\n");
        return NULL;
    }
    if(s!=NULL)
    {
        printf("栈已存在，无法初始化\n");
        return NULL;
    }
    s=(SqStack*)malloc(sizeof(SqStack));
    if(s==NULL)
    {
        printf("SqStack malloc error\n");
        return NULL;
    }
    s->elem=(int*)malloc(sizeof(int)*sizes);
    if(s->elem==NULL)
    {
        printf("SqStack's elem malloc error\n");
        free(s);
        s=NULL;
        return NULL;
    }
    s->size=sizes;
    s->top=-1;
    return s;
}



Status isEmptyStack(SqStack *s)//判断栈是否为空
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    if (s->top==-1)
    {
        printf("栈为空\n");
    }
    if(s->top==s->size-1)
    {
        printf("栈已满\n");
    }
    else printf("栈中有%d个元素",s->top+1);
    return SUCCESS;        
}



Status getTopStack(SqStack *s,ElemType e) //得到栈顶元素
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    if (s->top==-1)
    {
        printf("栈为空\n");
        return ERROR;
    }
    e=s->elem[s->top];
    printf("e=%d",s->elem[s->top]);
    return SUCCESS;
}

Status clearStack(SqStack *s)//清空栈
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }    
    s->top=-1;
    return SUCCESS;
}


Status destroyStack(SqStack *s)//销毁栈
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    free(s->elem);
    s->elem=NULL;
    free(s);
    s=NULL;
    printf("销毁栈成功！\n");
    return SUCCESS;
}


Status pushStack(SqStack *s,ElemType data)//入栈
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    if(s->top==s->size-1)
    {
        printf("栈已满，不支持该操作\n");
        return ERROR;
    }
    s->top++;
    (s->elem)[s->top]=data;
    printf("s->top=%d\n",s->top);
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType data)//出栈
{
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    if(s->top==-1)
    {
        printf("栈为空，不支持该操作\n");
        return ERROR;
    }
    data=(s->elem)[s->top];
    (s->top)--;
    printf("s->top=%d",s->top);
    return SUCCESS;
}



Status printStack(SqStack *s)
{
    int i=0;
    if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        return ERROR;
    }
    if(s->top==-1)
    {
        printf("栈为空，不支持该操作\n");
        return ERROR;
    }
    printf("Stack bottom ");
    for(;i<=s->top;i++)
    printf(" %d ",(s->elem)[i]);
    printf("  Stack top  \n");
    return SUCCESS;
    
}