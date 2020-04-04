#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SqStack.h"

void welcome();

/*主函数*/ 
void main()
{
	system("title 顺序栈练习  —— 刘欣羽");//设置标题 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    SqStack*s=NULL;
  A:system("cls");
    printf("                               栈主菜单（数组）\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---初始化栈                    2---销毁栈\n");
	printf("\n");
	printf("             3---判断栈是否为空              4---清空栈 \n");
	printf("\n");
	printf("             5---得到栈顶元素                6---输出栈内元素\n");
	printf("\n");			
	printf("             7---入栈                       8---出栈\n");
	printf("\n");
    printf("                                            9---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");		        
	printf("请输入序号：\n");
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
        case 1:
        {
            printf("请输入想生成的栈的长度\n");
            scanf("%d",&p);
            s=initStack(s,p);
            if(s!=NULL)
            printf("初始化成功！\n");
            system("pause");
            goto A;
        }
        case 2:
        {
            if(s==NULL)
            {
                printf("栈未初始化，无法进行此操作\n");
                system("pause");
                goto A;
            }
            Status(s);
            system("pause");
            goto A;
        }
        case 5:
        {
            if(s==NULL)
    {
        printf("栈不存在，不支持该操作\n");
        goto A;
    }
    if (s->top==-1)
    {
        printf("栈为空\n");
        goto A;
    }
        i=s->elem[s->top];
        printf("i=%d",s->elem[s->top]);

            printf("栈顶元素为%d\n",i);
            system("pause");
            goto A;
        }
        case 3:
        {
            isEmptyStack(s);
            system("pause");
            goto A;
        }
        case 4:
        {
            if(clearStack(s)==1)
            printf("清空栈成功\n",i);
            system("pause");
            goto A;
        }
        case 6:
        {
            if(printStack(s)==1)
            printf("输出成功\n",i);
            system("pause");
            goto A;
        }
        case 7:
        {
            printf("请输入入栈元素\n");
            scanf("%d",&i);
            if(pushStack(s,i)==1)
            printf("入栈成功！\n");
            system("pause");
            goto A;
        }
        case 8:
        {
            if(popStack(s,i)==1)
            printf("出栈成功！出栈元素为%d\n",i);
            system("pause");
            goto A;
        }
        case 9:destroyStack(s);break;
        default:printf("error\n");system("pause"); goto A;
    } 
    return; 
} 