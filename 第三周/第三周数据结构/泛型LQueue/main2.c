#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LQueue.h"

void welcome();
void enter(LQueue*Q);

/*������*/ 
void main()
{
	system("title ��������Ķ�����ϰ  ���� ������");//���ñ��� 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    LQueue*s=NULL;
  A:system("cls");
    printf("                             ��������Ķ������˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---��ʼ������                 2---���ٶ���\n");
	printf("\n");
	printf("             3---�ж϶����Ƿ�Ϊ��            4---��ն��� \n");
	printf("\n");
	printf("             5---�õ�����Ԫ��                6---��������\n");
	printf("\n");			
	printf("             7---���                       8---����\n");
	printf("\n");
    printf("             9---���г���                    10---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");		        
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch (choice)
    {
    case 1:s=InitLQueue(s);system("pause");goto A;
	case 2:s=DestoryLQueue(s);system("pause");goto A;
	case 3:IsEmptyLQueue(s);system("pause");goto A;
	case 4:ClearLQueue(s);system("pause");goto A;
	case 5:GetHeadLQueue(s);system("pause");goto A;
	case 6:TraverseLQueue(s);system("pause");goto A;
	case 7:enter(s);system("pause");goto A;
	case 8:DeLQueue(s);system("pause");goto A;
	case 9:p=LengthLQueue(s);printf("the length is %d",p);system("pause");goto A;
	case 10:DestoryLQueue(s);break;
    default:printf("error\n");goto A;
    }
}


void enter(LQueue*Q)
{
	int t;
	printf("��������������ͣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
    printf("��������\n");
    scanf("%d", &t);
    }
	printf("��ӵ�����:");
	fflush(stdin);
    switch(t)
    {
		case 1:{
			int a;
			scanf("%d", &a);
			EnLQueue(Q, &a,t);
		break;
		}
		case 2: {
			char a;
			scanf("%c", &a);
			EnLQueue(Q, &a,t);
			break;
		}
        case 3:{
			double a;
			scanf("%lf", &a);
			EnLQueue(Q, &a,t);
			break;
		}
        case 4:{
			char a[20];
			printf("��󳤶�Ϊ20\n");
			scanf("%s", &a);
			EnLQueue(Q, &a,t);
			break;
		}
	default:printf("error");
	}
}