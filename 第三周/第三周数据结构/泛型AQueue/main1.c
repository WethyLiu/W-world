#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"AQueue.h"

void welcome();
void enter(AQueue*Q);

/*������*/ 
void main()
{
	system("title ˳�������ϰ  ���� ������");//���ñ��� 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    AQueue*s=NULL;
  A:system("cls");
    printf("                             ˳��������˵������飩\n");
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
    printf("             9---�ж϶����Ƿ���              10---���г���\n");
	printf("\n");
	printf("                                            11---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("tip:�ö��������Ϊ10\n");
	printf("\n");
	printf("\n");		        
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch (choice)
    {
    case 1:s=InitAQueue(s);system("pause");goto A;
	case 2:s=DestoryAQueue(s);system("pause");goto A;
	case 3:IsEmptyAQueue(s);system("pause");goto A;
	case 4:ClearAQueue(s);system("pause");goto A;
	case 5:GetHeadAQueue(s);system("pause");goto A;
	case 6:TraverseAQueue(s);system("pause");goto A;
	case 7:enter(s);system("pause");goto A;
	case 8:DeAQueue(s);system("pause");goto A;
	case 9:IsFullAQueue(s);system("pause");goto A;
	case 10:p=LengthAQueue(s);printf("the length is %d",p);system("pause");goto A;
	case 11:break;
    default:printf("error\n");goto A;
    }
}


void enter(AQueue*Q)
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
			EnAQueue(Q, &a,t);
		break;
		}
		case 2: {
			char a;
			scanf("%c", &a);
			EnAQueue(Q, &a,t);
			break;
		}
        case 3:{
			double a;
			scanf("%lf", &a);
			EnAQueue(Q, &a,t);
			break;
		}
        case 4:{
			char a[20];
			printf("��󳤶�Ϊ20\n");
			scanf("%s", &a);
			EnAQueue(Q, &a,t);
			break;
		}
	default:printf("error");
	}
}