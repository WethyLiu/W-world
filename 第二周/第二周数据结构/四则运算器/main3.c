#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int Priority(char s) ;



void main()
{
    system("title �������������  ���� ������");
    LinkStack s,p;
    int a,b;
    a=initLStack(&s);      //��ʼ���������ݺͷ��ŵ�ջ
    b=initLStack(&p);
    if(a==0||b==0)
    {
        printf("��ʼ��ʧ��\n");
        system("pause");
        return;
    }
    char str[150]={0};	
    int i,temp,j,k;
    A:
    i=0;
    temp=0;
    printf("��������ʽ\n");
	scanf("%s",str);
	while(str[i]!='\0')   //�жϷǷ�����
    {
        if(str[i]<'0'||str[i]>'9')
        {
            if(str[i]!='*'&&str[i]!='/'&&str[i]!='+'&&str[i]!='-'&&str[i]!='('&&str[i] != ')')
            {
                printf("�Ƿ����룬������!\n");
                system("pause");
                goto A;
            }
        }
        i++;
    }
    
    i = 0;      //�ָ�i��ֵ
    printf("�沨�����ʽ:\n");
	while(str[i] != '\0' || isEmptyLStack(&p) != SUCCESS)
	{
		if(str[i] >= '0' && str[i] <= '9')  //�ж�����
		{
			temp = temp * 10 + str[i] - '0';    //�����洢��λ��
			i++;
			if(str[i] < '0' || str[i] > '9')        //�����ж��Ƿ�Ϊ��λ��
			{
				pushLStack(&s,temp);
                printf("%d",temp);
				temp = 0;
			}
		}
		else
		{
			if((isEmptyLStack(&p) == SUCCESS) || (getTopLStack(&p) == '(' && str[i] != ')') || Priority(str[i]) > Priority(getTopLStack(&p)))  //��ջ����������
			{
				pushLStack(&p,str[i]);
				i++;
				continue;
			}
			if(getTopLStack(&p) == '(' && str[i] == ')')  //��ջ����������
			{
				popLStack(&p);
				i++;
				continue;
			}
			if((str[i] == '\0' && isEmptyLStack(&p) != SUCCESS) || (str[i] == ')' && getTopLStack(&p) != '(') || Priority(str[i]) <= Priority(getTopLStack(&p)))//��ջ����������
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
    printf("�Ƿ����ʹ�ü�������Y/N\n");
    if(getchar()=='Y')
    {
        system("pause");
        goto A;
    }
    system("pause");
    return ;
}


int Priority(char s)    //���ȼ�����
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
