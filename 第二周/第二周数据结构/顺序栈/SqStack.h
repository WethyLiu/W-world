#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;   //定义指向数据的指针
	int top;      //指向栈顶的数据，是数组下标
	int size;     //栈空间的确切大小，数组元素个数，通过malloc动态分配空间
} SqStack;


SqStack*initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType data);//出栈
Status printStack(SqStack *s);//输出栈中元素内容


#endif 
