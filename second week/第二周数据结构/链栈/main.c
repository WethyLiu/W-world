#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"



void welcome();

void main()
{
	system("title ��ջ��ϰ  ���� ������");//���ñ��� 
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
    printf("                               ��ջ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---��ʼ��ջ                    2---����ջ\n");
	printf("\n");
	printf("             3---�ж�ջ�Ƿ�Ϊ��              4---���ջ \n");
	printf("\n");
	printf("             5---�õ�ջ��Ԫ��                6---���ջ��Ԫ��\n");
	printf("\n");			
	printf("             7---��ջ                       8---��ջ\n");
	printf("\n");
    printf("            9---���ջ����                   10---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("��������ţ�\n");
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
			printf("��������ջ�����ݣ�\n");
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
