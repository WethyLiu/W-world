#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SqStack.h"

void welcome();

/*������*/ 
void main()
{
	system("title ˳��ջ��ϰ  ���� ������");//���ñ��� 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    SqStack*s=NULL;
  A:system("cls");
    printf("                               ջ���˵������飩\n");
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
    printf("                                            9---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");		        
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
        case 1:
        {
            printf("�����������ɵ�ջ�ĳ���\n");
            scanf("%d",&p);
            s=initStack(s,p);
            if(s!=NULL)
            printf("��ʼ���ɹ���\n");
            system("pause");
            goto A;
        }
        case 2:
        {
            if(s==NULL)
            {
                printf("ջδ��ʼ�����޷����д˲���\n");
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
        printf("ջ�����ڣ���֧�ָò���\n");
        goto A;
    }
    if (s->top==-1)
    {
        printf("ջΪ��\n");
        goto A;
    }
        i=s->elem[s->top];
        printf("i=%d",s->elem[s->top]);

            printf("ջ��Ԫ��Ϊ%d\n",i);
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
            printf("���ջ�ɹ�\n",i);
            system("pause");
            goto A;
        }
        case 6:
        {
            if(printStack(s)==1)
            printf("����ɹ�\n",i);
            system("pause");
            goto A;
        }
        case 7:
        {
            printf("��������ջԪ��\n");
            scanf("%d",&i);
            if(pushStack(s,i)==1)
            printf("��ջ�ɹ���\n");
            system("pause");
            goto A;
        }
        case 8:
        {
            if(popStack(s,i)==1)
            printf("��ջ�ɹ�����ջԪ��Ϊ%d\n",i);
            system("pause");
            goto A;
        }
        case 9:destroyStack(s);break;
        default:printf("error\n");system("pause"); goto A;
    } 
    return; 
} 