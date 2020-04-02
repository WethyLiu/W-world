#include"duLinkedList.h"
#include"linkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define NUL '\0'


LNode*head1=NULL;  //单链表a 
LNode*head2=NULL;   //单链表b 
DuLNode*head3=NULL; //双向链表a
DuLNode*head4=NULL; //双向链表b
static int n;         //操作数记录链表状态

/*函数声明*/
void welcome();    //主菜单 
void Create();  //创建链表菜单 
void Single(int link);  //创建单链表 
void Double(int link);   //创建双向链表  
void Destroy();   //销毁链表菜单 
void ClearList();    //清零链表内容
void Choose();
void Print();    //打印链表内容
void Enter();    //输入数据
DuLNode* DuLinkedList_Menu(DuLNode*p);
LNode* LinkedList_Menu(LNode*p);
void Other();
void RanklinkedList(LinkedList*L,int n);    //单链表排序(后续会包含到头文件里)
void SwaplinkedList(LNode* p,LNode* q);   //交换p后和q后一结点的位置(后续会包含到头文件里)
void Merge();//合并链表操作
void MergelinkedList(LNode* head1,LNode* head2);  //合并单链表的函数(后续会包含到头文件里)
void MergelinkedList_Dul(DuLNode* head1,DuLNode* head2);

/*主函数*/ 
void main()
{
	system("title 链表练习  —— 刘欣羽");//设置标题 
	welcome();
	system("pause");
}

/*菜单*/
void welcome()
{
	int choice;  
  A:system("cls");
    printf("                              主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---创建链表                   2---销毁链表\n");
	printf("\n");
	printf("             3---输入数据                   4---清零链表 \n");
	printf("\n");
	printf("             5---打印链表                   6---其他操作\n");
	printf("\n");			
	printf("             7---合并链表                   8---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
    if(n==0)
        printf("提示：你一共可以创建两条链表   链表1：未创建    链表2：未创建\n");
    else if(n<10)
	        printf("提示：你一共可以创建两条链表   链表1：未创建    链表2：已创建\n");
	    else if(n==n/10*10)
	        printf("提示：你一共可以创建两条链表   链表1：已创建    链表2：未创建\n");
			else
                printf("提示：你一共可以创建两条链表   链表1：已创建    链表2：已创建\n");			
	printf("\n");		        
	printf("请输入序号：\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:Create();goto A;
        case 2:Destroy(); goto A;
        case 3:Enter();goto A;
        case 4:ClearList(); goto A;
        case 5:Print();goto A;
		case 6:Other();goto A;
		case 7:Merge();goto A;
        case 8:DestroyList(&head1);DestroyList(&head2);DestroyList_DuL(&head3);DestroyList_DuL(&head4);break;
        default:printf("error\n");goto A;
    } 
    return; 
} 

/*创建链表*/
void Create()
{
	int choice;
	int link; 
  A:system("cls");
    printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---单链表       2---双向链表          3---退出\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	
	printf("请输入序号：\n");
    fflush(stdin);
    scanf("%d",&choice);
	if(choice==3)goto B;
	if(choice!=1&&choice!=2)
	{
		printf("输入有误！\n");
		system("pause");
		goto A;
	}
	printf("请输入需要生成链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}	
	if((n>=10&&link==1)||(n>0&&n<10&&link==2))
	{
		printf("无法新增链表\n");
		system("pause"); 
        return;	
	}   
    switch(choice)
    {
        case 1:Single(link);break;
        case 2:Double(link);break;
        case 3:break;
        default:printf("error\n");system("pause");goto A;
    } 
   B: return; 	
}

/*创建单链表*/
void Single(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("请输入链表长度\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("请输入大于1整数！\n");
		goto A;
	}
    head=(LinkedList)malloc(sizeof(LNode));
	q=head;
	q->data=0;
	q->next=NULL;	
	for (int j=1;j<i;j++)
	{
		if(InitList(&p)==1)
		{
            q->next=p;
			q=q->next;
			q->data=j;
		}
        else
		{
			printf("生成新节点过程出错\n");  //不足：已生成结点需要删掉 引用删除函数
			return;
		}
	}
	if (link==1)
	{
		n=n+10;
		head1=head;
	}
	else 
	{
		n=n+1;
		head2=head;
	}
	printf("成功创建链表！\n");
} 
/*创建双向链表*/
void Double(int link)
{
    	int i;
	DuLNode*head,*p,*q;
  A:printf("请输入链表长度\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("请输入大于零整数！\n");
		goto A;
	}
    head=(DuLinkedList)malloc(sizeof(DuLNode));
	q=head;
	q->data=0;
	head->prior=NULL;
    for (int j=1;j<i;j++)
	{
		if(InitList_DuL(&p)==1)
		{
            q->next=p;
			p->prior=q;
			q=q->next;
			q->data=j;
		}
        else
		{
			printf("生成新节点过程出错\n");  //不足：已生成结点需要删掉 引用删除函数
			return;
		}
	}
	if (link==1)
	{
		n=n+20;
		head3=head;
	}
	else 
	{
		n=n+2;
		head4=head;
	}
	printf("成功创建链表！\n");
} 


/*销毁链表*/
void Destroy()
{
	int link; 
  A:system("cls");
    Choose();
	printf("请输入需要销毁链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}	
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("链表未生成，无法销毁\n");
		system("pause"); 
        return;	
	}   	
    switch(link)
    {
        case 1:
		{
			if (n/10==1)DestroyList(&head1);
			else DestroyList_DuL(&head3);
			n=n-n/10*10;
			if(head1==NULL&&head3==NULL)
         	printf("销毁链表%d成功\n",link);
			system("pause");
			break;
		}
        case 2:
		{
			if (n%10==1)DestroyList(&head2);
			else DestroyList_DuL(&head4);
			n=n-n%10;
			if(head2==NULL&&head4==NULL)
         	printf("销毁链表%d成功\n",link);
			system("pause");
			break;
		}
        default:printf("error\n");system("pause");goto A;
    } 
	
    return; 	
}

/*清空结点内容*/
void ClearList()
{
	int link; 
  A:system("cls");
    Choose();
	printf("请输入需要清零链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("链表未生成，无法清零\n");
		system("pause"); 
        return;	
	}  
	LNode*p;
	DuLNode*q; 	
	switch(link)
	{
		case 1:
		{	
			if (n/10==1)
			    for(p=head1;p!=NULL;p=p->next)
			       { p->data=0;}
			else if(n/10==2)
			    for(q=head3;q!=NULL;q=q->next)
                    q->data=0;
			printf("清零1成功\n");
			break;
		}
		case 2:
		{
			if (n%10==1)
			    for(p=head2;p!=NULL;p=p->next)
			        p->data=0;
			else if (n%10==2)
			    for(q=head4;q!=NULL;q=q->next)
                    q->data=0;
			printf("清零2成功\n");
			break;
		}
	}
	system("pause");
}


/*选择操作*/
void Choose()
{
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("               1---链表1                 2---链表2 \n");
	printf("\n");	
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	

}

/*打印链表*/
void Print()
{
	int link; 
  A:system("cls");
    Choose();
	printf("请输入需要打印链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("链表未生成，无法打印\n");
		system("pause"); 
        return;	
	}   	
    switch(link)
	{
		case 1:
		{
			if (n/10==1)
			   { TraverseList(head1);system ("pause");}
			if(n/10==2)
			    TraverseList_DuL(head3);
			break;
		}
		case 2:
		{
			if (n%10==1)
			    TraverseList(head2);
			else
			    TraverseList_DuL(head4);
			break;
		}
		default:printf("error\n");break;
	}
	printf("打印成功\n");
	system("pause");
}

/*输入数据*/
void Enter()
{
	int link; 
  A:system("cls");
    Choose();
	printf("请输入需要输入链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("链表未生成，无法输入\n");
		system("pause"); 
        return;	
	}   	
	LNode*p;
	DuLNode*q; 
	fflush(stdin);
	printf("请输入数据，输入-1时终止\n");	
    switch(link)
	{
		
		case 1:
		{	
			if (n/10==1)
			    for(p=head1;p!=NULL;p=p->next)
			        {
					    scanf("%d",&(p->data));
					    if(p->data==-1){p->data=0;break;}
				    }
			else if(n/10==2)
			    for(q=head3;q!=NULL;q=q->next)
 			        {
					    scanf("%d",&(q->data));
					    if(q->data==-1){q->data=0;break;}
				    }
			break;
		}
		case 2:
		{
			if (n%10==1)
			    for(p=head2;p!=NULL;p=p->next)
			        {
					    scanf("%d",&(p->data));
					    if(p->data==-1){p->data=0;break;}
				    }
			else if (n%10==2)
			    for(q=head4;q!=NULL;q=q->next)
 			       {
					    scanf("%d",&(q->data));
					    if(q->data==-1){q->data=0;break;}
				    }
			break;
		}
	}
	printf("输入数据成功\n");
	system("pause");

}

/*其他功能*/
void Other()
{
	LNode*p=NULL;
	DuLNode*q=NULL; 
	int link;	
	A:system("cls");
    Choose();
	printf("请输入需要操作链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");link=0;system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{ 
        printf("代号abcdc有误\n");
		system("pause");
		return;	
	}   	
	fflush(stdin);	
    switch(link)
	{
		
		case 1:
		{	
			if (n/10==1)
			{p=head1;}
			else if(n/10==2)
			{q=head3;}
			break;
		}
		case 2:
		{
			if (n%10==1)
            {p=head2;}
			else if (n%10==2)
			{q=head4;}
			break;
		}
	}
	if (p==NULL&&q==NULL)
	{
		printf("不存在链表无法执行此操作\n");
		system("pause");
		return;
	}
	if(p!=NULL&&link==1)head1=LinkedList_Menu(p);
	if(p!=NULL&&link==2)head2=LinkedList_Menu(p);
	if(q!=NULL&&link==1)head3=DuLinkedList_Menu(q);
	if(q!=NULL&&link==2)head4=DuLinkedList_Menu(q);
    return;
}



/* 单链表操作菜单*/
LNode* LinkedList_Menu(LNode*p)
{
	int i;
	LNode*q,*g;
  A:system("cls");
    printf("                            单链表操作菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---插入结点                    2---删除结点\n");
	printf("\n");
	printf("             3---查找结点                    4---逆转链表 \n");
	printf("\n");
	printf("             5---交换奇偶结点                6---定位中间结点\n");
	printf("\n");			
	printf("             7---按结点数据排序              8---交换任意两结点\n");
	printf("\n");
	printf("                                            9---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	for(i=0,q=p;q!=NULL;q=q->next,i++);/* code */
    printf("提示：此表共有%d个结点\n",i);
	printf("链表内容：\n");
	TraverseList(p);
	int j,f,h;
	printf("\n");
	printf("请输入序号：\n");
	int choice;
    fflush(stdin);
    scanf("%d",&choice);
	fflush(stdin);
    switch(choice)
    {
        case 1:
		{
			printf("请输入新结点要插入在第几个结点之后\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("输入数据错误\n");goto A;
			}
			for(f=1,q=p;f<j;f++,q=q->next);
			g=(LinkedList)malloc(sizeof(LNode));
			printf("请输入新结点数据\n");
			scanf("%d",&(g->data));
			InsertList(q,g);
			system("pause");
			TraverseList(p);
			goto A;
		}
        case 2: 
		{
			printf("请输入要删除第几个结点\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("输入数据错误\n");goto A;
			}
			if(p==NULL||p->next==NULL)
			{
				printf("只剩一个结点，无法执行此操作\n");
				system("pause");
				goto A;
			}
			if(j==1)
			{
				q=p;
				f=q->data;
				p=q->next;
				q->next=NULL;
				free(q);
			}
			else
			{
				for(f=1,q=p;f<j-1;f++,q=q->next);
				f=q->next->data;
				DeleteList(q);/* code */
			}
			printf("删除的是第%d个结点，数据是%d\n",j,f);
			TraverseList(p);
			system("pause");
			goto A;
		}
        case 3:
		{
			printf("请输入要查询的数据\n");
			scanf("%d",&f);
			SearchList(&p,f);
		    system("pause");                	                   //此处本来想用头文件中的函数，但是一用就闪退。。。
			goto A;
		}       
        case 4:
		{
			printf("逆转前：\n");
			TraverseList(p);
			ReverseList(&p);
			printf("逆转后：\n");
			TraverseList(p); 
			system("pause");
			goto A;
		}
        case 5:ReverseEvenList(&p);printf("奇偶转换后\n");TraverseList(p);system("pause"); goto A;
		case 6:q=FindMidNode(&p);printf("中间结点的数据为%d\n",q->data);system("pause"); goto A;
		case 7:RanklinkedList(&p,i);printf("排序后\n");TraverseList(p);system("pause");goto A;
		case 8:
		{
			q=p;
			g=p;
			printf("请输入想要交换的两个结点\n");
			printf("结点a:");
			scanf("%d",&j);
			if(j<=0||j>i)
			{
				printf("输入数据有误\n");
				system("pause");
				goto A;
			}
			if(j==1)
			{
				q=(LinkedList)malloc(sizeof(LNode));
				q->next=p;
			}
			else for(f=1;f<j-1;q=q->next,f++);
			printf("结点b:");
			scanf("%d",&h);
			if(h<=0||h>i)
			{
				printf("输入数据有误\n");
				system("pause");
				goto A;
			}
			if(h==1)
			{
				g=(LinkedList)malloc(sizeof(LNode));
				g->next=p;
			}
			else for(f=1;f<h-1;g=g->next,f++);
			if(j==h)
			{
				if(g->next==p)
				{g->next=NULL;q=NULL;free(g);}
				printf("不需要交换\n");
				system("pause");
				goto A;
			}
			SwaplinkedList(q,g);
			if(j==1)
			{
				p=q->next;
				q->next=NULL;
				free(q);
			}
			if(h==1)
			{
				p=g->next;
				g->next=NULL;
				free(g);
			}
			printf("交换后:\n");
			TraverseList(p);
			system("pause");
			goto A;
		}
        case 9:break;
        default:printf("error\n");goto A;
    } 
    system("pause");
    return p;	
}

/*单链表排序函数*/
void RanklinkedList(LinkedList*L,int n)
{
	int f=0;
	printf("1----升序   2----降序\n");
	fflush(stdin);
    scanf("%d",&f);
	if (f!=1&&f!=2)
	{
		printf("代号有误\n");f=0;system("pause");return;
	}
	int i,j;
    LinkedList p,q;
    q=(LinkedList)malloc(sizeof(LNode));
    q->data=1;
	q->next=(*L),(*L)=q;
	for(i=0;i<n-1;i++)
    {
    for(j=0;j<n-1-i;j++)
        {
        p=q->next;
		if(f==2)
        if((p->data)<(p->next->data))
            {
            q->next=p->next;
            p->next=q->next->next;
            q->next->next=p;
            }
		if(f==1)
		if((p->data)>(p->next->data))
            {
            q->next=p->next;
            p->next=q->next->next;
            q->next->next=p;
            }
        q=q->next,p=q->next;
        }
    q=(*L);
    }
    (*L)=(*L)->next,q->next=NULL;
    free(q);
    return;
}


/*交换单链表任意两点的函数*/
void SwaplinkedList(LNode* p,LNode* q)       //交换p随后一结点和q后一节点位置
{
    LNode*f;
	f=p->next;
	p->next=f->next;
	f->next=q->next->next;
	q->next->next=f;
	f=q->next;
	q->next=f->next;
	f->next=p->next;
	p->next=f;
}



DuLNode* DuLinkedList_Menu(DuLNode*p)
{
	int i;
	DuLNode*q,*g;
  A:system("cls");
    printf("                            双向链表操作菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---向前插入结点                2---向后插入结点\n");
	printf("\n");
	printf("             3---查找结点                    4---删除结点 \n");
	printf("\n");
	printf("                                             5---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	for(i=0,q=p;q!=NULL;q=q->next,i++);/* code */
    printf("提示：此表共有%d个结点\n",i);
	printf("链表内容：\n");
	TraverseList_DuL(p);
	int j,h,f;
	printf("\n");
	printf("请输入序号：\n");
	int choice;
    fflush(stdin);
    scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
		case 1:
		{
			printf("请输入新结点要插入在第几个结点之前\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("输入数据错误\n");goto A;
			}
			q=p;
			for(f=1;f<j;f++,q=q->next);
			g=(DuLinkedList)malloc(sizeof(DuLNode));
			g->next=NULL;
			g->prior=NULL;
			printf("请输入新结点数据\n");
			scanf("%d",&(g->data));
			InsertBeforeList_DuL(q,g);
			if(j==1)p=g;
			TraverseList_DuL(p);
			system("pause");
			goto A;
		}
        case 2:
		{
			printf("请输入新结点要插入在第几个结点之后\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("输入数据错误\n");goto A;
			}
			for(f=1,q=p;f<j;f++,q=q->next);
			g=(DuLinkedList)malloc(sizeof(DuLNode));
			g->next=NULL;
			g->prior=NULL;
			printf("请输入新结点数据\n");
			scanf("%d",&(g->data));
			InsertAfterList_DuL(q,g);
			TraverseList_DuL(p);
			system("pause");
			goto A;
		}
		case 3:
		{
			printf("请输入要查询的数据\n");
			scanf("%d",&f);
			q=p;
			for(j=1;q!=NULL;j++,q=q->next)
			{
				if(q->data==f)
				printf("第%d个结点出现数据%d\n",j,f);
			}
		    system("pause"); 
			goto A;
		}
	    case 4: 
		{
			printf("请输入要删除第几个结点\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("输入数据错误\n");goto A;
			}
			if(p==NULL||p->next==NULL)
			{
				printf("只剩一个结点，无法执行此操作\n");
				system("pause");
				goto A;
			}
			if(j==1)
			{
				q=p;
				f=q->data;
				p=q->next;
				q->next=NULL;
				free(q);
			}
			else
			{
				for(f=1,q=p;f<j-1;f++,q=q->next);
				f=q->next->data;
				DeleteList_DuL(q);/* code */
			}
			printf("删除的是第%d个结点，数据是%d\n",j,f);
			TraverseList_DuL(p);
			system("pause");
			goto A;
		}

		case 5:break;
	}
	system("pause");
	return p;
}


void Merge()
{
	if (n!=11&&n!=22)
	{
		printf("可能由于链表未生成两条或者类型不同,无法进行此操作");
		system("pause");
		return;
	}
	if(n==11)
	{
		MergelinkedList(head1,head2);
		printf("合并至链表1\n");
		TraverseList(head1);
		n=10;
		system("pause");
	}
	if(n==22)
	{
		MergelinkedList_Dul(head3, head4);
		printf("合并至链表1\n");
		TraverseList_DuL(head3);
		n=20;
		system("pause");
	}
		
}


void MergelinkedList(LNode* head1,LNode* head2)
{
	LNode*p,*q,*h;
	h=NULL;
	p=head1;
	q=head2;
	while (1)
	{
		h=p->next;
		if(q==NULL)break;
		p->next=q;
		q=q->next;
		p=p->next;
		if(h==NULL)break;
		p->next=h;
		p=h;
	}
	head2=NULL;
	
}


void MergelinkedList_Dul(DuLNode* head1,DuLNode* head2)
{
	DuLNode*p,*q,*h;
	h=NULL;
	p=head1;
	q=head2;
	while (1)
	{
		h=p->next;
		if(q==NULL)break;
		p->next=q;q->prior=p;
		q=q->next;
		p=p->next;
		if(h==NULL)break;
		p->next=h;h->prior=p;
		p=h;
	}
	head2=NULL;
	
}