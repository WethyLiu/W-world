#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"



void welcome();

void main()
{
	system("title 链栈练习  —— 刘欣羽");//设置标题 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i;
	int p; 
	int *q;
	LinkStack*t;
	t=NULL;
  A:system("cls");
    printf("                               链栈主菜单\n");
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
    printf("            9---检测栈长度                   10---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("请输入序号：\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
		{
			initLStack(&t);
			system("pause");
			goto A;
		}
		case 2:
		{
			destroyLStack(&t);
			system("pause");
			goto A;
		}
		case 3:
		{
			isEmptyLStack(t);
			system("pause");
			goto A;
		}
		case 4:
		{
			clearLStack(t);
			system("pause");
			goto A;
		}
		case 5:
		{
			getTopLStack(t,p);
			system("pause");
			goto A;
		}
		case 6:
		{
			printfLStack(t);
			system("pause");
			goto A;
		}
		case 7:
		{
			printf("请输入入栈的数据：\n");
			scanf("%d",&i);
			pushLStack(t,i);
			system("pause");
			goto A;
		}
		case 8:
		{
			popLStack(t,p);
			system("pause");
			goto A;
		}
		case 9:
		{
			LStackLength(t,p);
			system("pause");
			goto A;
		}
		case 10:destroyLStack(&t);break;
        default:printf("error\n");goto A;
    } 
}
