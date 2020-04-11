#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"AQueue.h"

void welcome();
void enter(AQueue*Q);

/*主函数*/ 
void main()
{
	system("title 顺序队列练习  —— 刘欣羽");//设置标题 
	welcome();
	system("pause");
}

void welcome()
{
	int choice,i,p; 
    AQueue*s=NULL;
  A:system("cls");
    printf("                             顺序队列主菜单（数组）\n");
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
    printf("             9---判断队列是否满              10---队列长度\n");
	printf("\n");
	printf("                                            11---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("tip:该队列最长长度为10\n");
	printf("\n");
	printf("\n");		        
	printf("请输入序号：\n");
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
			printf("最大长度为20\n");
			scanf("%s", &a);
			EnAQueue(Q, &a,t);
			break;
		}
	default:printf("error");
	}
}