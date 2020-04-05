#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
    s->count = 0;
    s->top = NULL;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
    if(s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

int getTopLStack(LinkStack *s)  //得到栈顶元素
{
    if(s->count == 0)  //判断链栈是否为空
    {
        return ERROR;
    }
    return s->top->data;
}

Status clearLStack(LinkStack *s)   //清空栈
{
    LinkStackPtr pre;
    if(s->count == 0)  //判断链栈是否为空
    {
        return ERROR;
    }
    pre = s->top;
    while(s->top)       //释放链栈内存，直至栈底
    {
        s->top = pre->next;
        free(pre);
        pre = s->top;
    }
    s->count = 0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
    LinkStackPtr pre;
    if(s->count == 0)  //判断链栈是否为空
    {
        s->count = -1;
        return ERROR;
    }
    pre = s->top;
    while(s->top)       //释放链栈内存，直至栈底
    {
        s->top = pre->next;
        free(pre);
        pre = s->top;
    }
    s->count = -1;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,ElemType *length)    //检测栈长度
{
    if(s->count == 0)  //判断链栈是否为空
    {
        (*length) = 0;
        return ERROR;
    }
    (*length) = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
    LinkStackPtr pre = (LinkStackPtr)malloc(sizeof(struct StackNode));
    if(s->count == 0)  //判断链栈是否为空,如果为空则next指向NULL，否则指向上一次栈顶元素
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

int popLStack(LinkStack *s)   //出栈
{
    int temp;
    LinkStackPtr pre;
    if(s->count == 0)  //判断链栈是否为空
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


