#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


Status initLStack(LinkStack **s)//初始化栈
{
    if((*s)!=NULL)
    {
        printf("栈已存在，无法初始化\n");
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
    printf("初始化成功\n");
    return SUCCESS;    
}





Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
        return ERROR;
    }
    if(s->top==NULL)
    printf("当前栈为空\n");
    else
    {
        printf("当前栈不为空\n");
    }
    return SUCCESS;
}



Status getTopLStack(LinkStack *s,ElemType e)//得到栈顶元素
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
        return ERROR;
    }
    if(s->top==NULL)
    {
        printf("栈中无元素\n");
        return ERROR;
    }
    e=s->top->data;
    printf("栈顶元素为%d",s->top->data);
    return SUCCESS;
}


Status clearLStack(LinkStack *s)//清空栈
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
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
    printf("清空成功\n");
    return SUCCESS;
}




Status destroyLStack(LinkStack **s)//销毁栈
{
    if((*s)==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
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
    printf("销毁成功\n");
    return SUCCESS;
}


Status LStackLength(LinkStack *s,int length)    //检测链zhan长度
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
        return ERROR;
    }
    length = s->count;
    printf("链栈长度为：%d\n",length);
    return SUCCESS;
}


Status pushLStack(LinkStack *s,ElemType data)//入栈
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
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
    printf("入栈成功！\n");
    return SUCCESS;
}



Status popLStack(LinkStack *s,ElemType datas)   //出栈
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
        return ERROR;
    }
    if(s->top == NULL) {printf("空链栈不执行！\n"); return ERROR;}

    LinkStackPtr current;
    datas = s->top->data;
    current = s->top;
    s->top = s->top->next;
    free(current);
    s->count--;
    printf("出栈元素为：%d\n",datas);
    return SUCCESS;
}





Status printfLStack(LinkStack*s)
{
    if(s==NULL)
    {
        printf("栈未初始化，无法进行此操作\n");
        return ERROR;
    }
    LinkStackPtr p;
    p=s->top;
    for(;p!=NULL;p=p->next)
    printf(" %d ",p->data);
    return SUCCESS;
}