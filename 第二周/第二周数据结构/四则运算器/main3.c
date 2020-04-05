#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int Priority(char s) ;



void main()
{
    system("title 四则运算计算器  —— 刘欣羽");
    LinkStack s,p;
    int a,b;
    a=initLStack(&s);      //初始化放置数据和符号的栈
    b=initLStack(&p);
    if(a==0||b==0)
    {
        printf("初始化失败\n");
        system("pause");
        return;
    }
    char str[150]={0};	
    int i,temp,j,k;
    A:
    i=0;
    temp=0;
    printf("请输入算式\n");
	scanf("%s",str);
	while(str[i]!='\0')   //判断非法输入
    {
        if(str[i]<'0'||str[i]>'9')
        {
            if(str[i]!='*'&&str[i]!='/'&&str[i]!='+'&&str[i]!='-'&&str[i]!='('&&str[i] != ')')
            {
                printf("非法输入，请重试!\n");
                system("pause");
                goto A;
            }
        }
        i++;
    }
    
    i = 0;      //恢复i的值
    printf("逆波兰表达式:\n");
	while(str[i] != '\0' || isEmptyLStack(&p) != SUCCESS)
	{
		if(str[i] >= '0' && str[i] <= '9')  //判断数字
		{
			temp = temp * 10 + str[i] - '0';    //用来存储多位数
			i++;
			if(str[i] < '0' || str[i] > '9')        //用来判断是否为多位数
			{
				pushLStack(&s,temp);
                printf("%d",temp);
				temp = 0;
			}
		}
		else
		{
			if((isEmptyLStack(&p) == SUCCESS) || (getTopLStack(&p) == '(' && str[i] != ')') || Priority(str[i]) > Priority(getTopLStack(&p)))  //进栈不参与运算
			{
				pushLStack(&p,str[i]);
				i++;
				continue;
			}
			if(getTopLStack(&p) == '(' && str[i] == ')')  //出栈不参与运算
			{
				popLStack(&p);
				i++;
				continue;
			}
			if((str[i] == '\0' && isEmptyLStack(&p) != SUCCESS) || (str[i] == ')' && getTopLStack(&p) != '(') || Priority(str[i]) <= Priority(getTopLStack(&p)))//出栈并参与运算
			{
				k=popLStack(&p);
                printf("%c",k);
                switch(k)
				{
					case '+':
						pushLStack(&s, popLStack(&s) + popLStack(&s));
						break;
					case '-':
						j = popLStack(&s);
						pushLStack(&s, popLStack(&s) - j);
						break;
					case '*':
						pushLStack(&s, popLStack(&s) * popLStack(&s));
						break;
					case '/':
						j = popLStack(&s);
						pushLStack(&s, popLStack(&s) / j);
				}
				continue;
			}
		}
    }
    printf("=%d",popLStack(&s));
    printf("\n");
    printf("是否继续使用计算器？Y/N\n");
    if(getchar()=='Y')
    {
        system("pause");
        goto A;
    }
    system("pause");
    return ;
}


int Priority(char s)    //优先级函数
{
	switch(s)
	{
		case '(':
		case ')':
			return 3;
		case '*':

		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
