#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LQueue.h"

void welcome();
void enter(LQueue*Q);

/*主函数*/ 
void main()
{
	system("title 基于链表的队列练习  —— 刘欣羽");//设置标题 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    LQueue*s=NULL;
  A:system("cls");
    printf("                             基于链表的队列主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---初始化队列                 2---销毁队列\n");
	printf("\n");
	printf("             3---判断队列是否为空            4---清空队列 \n");
	printf("\n");
	printf("             5---得到队首元素                6---遍历队列\n");
	printf("\n");			
	printf("             7---入队                       8---出队\n");
	printf("\n");
    printf("             9---队列长度                    10---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");		        
	printf("请输入序号：\n");
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
	printf("你想入队哪种类型？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
    printf("输入有误\n");
    scanf("%d", &t);
    }
	printf("入队的数据:");
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
			printf("最大长度为20\n");
			scanf("%s", &a);
			EnLQueue(Q, &a,t);
			break;
		}
	default:printf("error");
	}
}