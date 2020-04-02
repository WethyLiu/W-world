#include"duLinkedList.h"
#include"linkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define NUL '\0'


LNode*head1=NULL;  //������a 
LNode*head2=NULL;   //������b 
DuLNode*head3=NULL; //˫������a
DuLNode*head4=NULL; //˫������b
static int n;         //��������¼����״̬

/*��������*/
void welcome();    //���˵� 
void Create();  //��������˵� 
void Single(int link);  //���������� 
void Double(int link);   //����˫������  
void Destroy();   //��������˵� 
void ClearList();    //������������
void Choose();
void Print();    //��ӡ��������
void Enter();    //��������
DuLNode* DuLinkedList_Menu(DuLNode*p);
LNode* LinkedList_Menu(LNode*p);
void Other();
void RanklinkedList(LinkedList*L,int n);    //����������(�����������ͷ�ļ���)
void SwaplinkedList(LNode* p,LNode* q);   //����p���q��һ����λ��(�����������ͷ�ļ���)
void Merge();//�ϲ��������
void MergelinkedList(LNode* head1,LNode* head2);  //�ϲ�������ĺ���(�����������ͷ�ļ���)
void MergelinkedList_Dul(DuLNode* head1,DuLNode* head2);

/*������*/ 
void main()
{
	system("title ������ϰ  ���� ������");//���ñ��� 
	welcome();
	system("pause");
}

/*�˵�*/
void welcome()
{
	int choice;  
  A:system("cls");
    printf("                              ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---��������                   2---��������\n");
	printf("\n");
	printf("             3---��������                   4---�������� \n");
	printf("\n");
	printf("             5---��ӡ����                   6---��������\n");
	printf("\n");			
	printf("             7---�ϲ�����                   8---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
    if(n==0)
        printf("��ʾ����һ�����Դ�����������   ����1��δ����    ����2��δ����\n");
    else if(n<10)
	        printf("��ʾ����һ�����Դ�����������   ����1��δ����    ����2���Ѵ���\n");
	    else if(n==n/10*10)
	        printf("��ʾ����һ�����Դ�����������   ����1���Ѵ���    ����2��δ����\n");
			else
                printf("��ʾ����һ�����Դ�����������   ����1���Ѵ���    ����2���Ѵ���\n");			
	printf("\n");		        
	printf("��������ţ�\n");
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

/*��������*/
void Create()
{
	int choice;
	int link; 
  A:system("cls");
    printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---������       2---˫������          3---�˳�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
	if(choice==3)goto B;
	if(choice!=1&&choice!=2)
	{
		printf("��������\n");
		system("pause");
		goto A;
	}
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}	
	if((n>=10&&link==1)||(n>0&&n<10&&link==2))
	{
		printf("�޷���������\n");
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

/*����������*/
void Single(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("������������\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("���������1������\n");
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
			printf("�����½ڵ���̳���\n");  //���㣺�����ɽ����Ҫɾ�� ����ɾ������
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
	printf("�ɹ���������\n");
} 
/*����˫������*/
void Double(int link)
{
    	int i;
	DuLNode*head,*p,*q;
  A:printf("������������\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("�����������������\n");
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
			printf("�����½ڵ���̳���\n");  //���㣺�����ɽ����Ҫɾ�� ����ɾ������
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
	printf("�ɹ���������\n");
} 


/*��������*/
void Destroy()
{
	int link; 
  A:system("cls");
    Choose();
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}	
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("����δ���ɣ��޷�����\n");
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
         	printf("��������%d�ɹ�\n",link);
			system("pause");
			break;
		}
        case 2:
		{
			if (n%10==1)DestroyList(&head2);
			else DestroyList_DuL(&head4);
			n=n-n%10;
			if(head2==NULL&&head4==NULL)
         	printf("��������%d�ɹ�\n",link);
			system("pause");
			break;
		}
        default:printf("error\n");system("pause");goto A;
    } 
	
    return; 	
}

/*��ս������*/
void ClearList()
{
	int link; 
  A:system("cls");
    Choose();
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("����δ���ɣ��޷�����\n");
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
			printf("����1�ɹ�\n");
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
			printf("����2�ɹ�\n");
			break;
		}
	}
	system("pause");
}


/*ѡ�����*/
void Choose()
{
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("               1---����1                 2---����2 \n");
	printf("\n");	
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	

}

/*��ӡ����*/
void Print()
{
	int link; 
  A:system("cls");
    Choose();
	printf("��������Ҫ��ӡ������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("����δ���ɣ��޷���ӡ\n");
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
	printf("��ӡ�ɹ�\n");
	system("pause");
}

/*��������*/
void Enter()
{
	int link; 
  A:system("cls");
    Choose();
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{
		printf("����δ���ɣ��޷�����\n");
		system("pause"); 
        return;	
	}   	
	LNode*p;
	DuLNode*q; 
	fflush(stdin);
	printf("���������ݣ�����-1ʱ��ֹ\n");	
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
	printf("�������ݳɹ�\n");
	system("pause");

}

/*��������*/
void Other()
{
	LNode*p=NULL;
	DuLNode*q=NULL; 
	int link;	
	A:system("cls");
    Choose();
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");link=0;system("pause");return;
	}
	if((n==0)||((n/10==0)&&(link==1))||((n%10==0)&&(link==2)))
	{ 
        printf("����abcdc����\n");
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
		printf("�����������޷�ִ�д˲���\n");
		system("pause");
		return;
	}
	if(p!=NULL&&link==1)head1=LinkedList_Menu(p);
	if(p!=NULL&&link==2)head2=LinkedList_Menu(p);
	if(q!=NULL&&link==1)head3=DuLinkedList_Menu(q);
	if(q!=NULL&&link==2)head4=DuLinkedList_Menu(q);
    return;
}



/* ����������˵�*/
LNode* LinkedList_Menu(LNode*p)
{
	int i;
	LNode*q,*g;
  A:system("cls");
    printf("                            ����������˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---������                    2---ɾ�����\n");
	printf("\n");
	printf("             3---���ҽ��                    4---��ת���� \n");
	printf("\n");
	printf("             5---������ż���                6---��λ�м���\n");
	printf("\n");			
	printf("             7---�������������              8---�������������\n");
	printf("\n");
	printf("                                            9---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	for(i=0,q=p;q!=NULL;q=q->next,i++);/* code */
    printf("��ʾ���˱���%d�����\n",i);
	printf("�������ݣ�\n");
	TraverseList(p);
	int j,f,h;
	printf("\n");
	printf("��������ţ�\n");
	int choice;
    fflush(stdin);
    scanf("%d",&choice);
	fflush(stdin);
    switch(choice)
    {
        case 1:
		{
			printf("�������½��Ҫ�����ڵڼ������֮��\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("�������ݴ���\n");goto A;
			}
			for(f=1,q=p;f<j;f++,q=q->next);
			g=(LinkedList)malloc(sizeof(LNode));
			printf("�������½������\n");
			scanf("%d",&(g->data));
			InsertList(q,g);
			system("pause");
			TraverseList(p);
			goto A;
		}
        case 2: 
		{
			printf("������Ҫɾ���ڼ������\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("�������ݴ���\n");goto A;
			}
			if(p==NULL||p->next==NULL)
			{
				printf("ֻʣһ����㣬�޷�ִ�д˲���\n");
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
			printf("ɾ�����ǵ�%d����㣬������%d\n",j,f);
			TraverseList(p);
			system("pause");
			goto A;
		}
        case 3:
		{
			printf("������Ҫ��ѯ������\n");
			scanf("%d",&f);
			SearchList(&p,f);
		    system("pause");                	                   //�˴���������ͷ�ļ��еĺ���������һ�þ����ˡ�����
			goto A;
		}       
        case 4:
		{
			printf("��תǰ��\n");
			TraverseList(p);
			ReverseList(&p);
			printf("��ת��\n");
			TraverseList(p); 
			system("pause");
			goto A;
		}
        case 5:ReverseEvenList(&p);printf("��żת����\n");TraverseList(p);system("pause"); goto A;
		case 6:q=FindMidNode(&p);printf("�м��������Ϊ%d\n",q->data);system("pause"); goto A;
		case 7:RanklinkedList(&p,i);printf("�����\n");TraverseList(p);system("pause");goto A;
		case 8:
		{
			q=p;
			g=p;
			printf("��������Ҫ�������������\n");
			printf("���a:");
			scanf("%d",&j);
			if(j<=0||j>i)
			{
				printf("������������\n");
				system("pause");
				goto A;
			}
			if(j==1)
			{
				q=(LinkedList)malloc(sizeof(LNode));
				q->next=p;
			}
			else for(f=1;f<j-1;q=q->next,f++);
			printf("���b:");
			scanf("%d",&h);
			if(h<=0||h>i)
			{
				printf("������������\n");
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
				printf("����Ҫ����\n");
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
			printf("������:\n");
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

/*������������*/
void RanklinkedList(LinkedList*L,int n)
{
	int f=0;
	printf("1----����   2----����\n");
	fflush(stdin);
    scanf("%d",&f);
	if (f!=1&&f!=2)
	{
		printf("��������\n");f=0;system("pause");return;
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


/*������������������ĺ���*/
void SwaplinkedList(LNode* p,LNode* q)       //����p���һ����q��һ�ڵ�λ��
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
    printf("                            ˫����������˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---��ǰ������                2---��������\n");
	printf("\n");
	printf("             3---���ҽ��                    4---ɾ����� \n");
	printf("\n");
	printf("                                             5---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	for(i=0,q=p;q!=NULL;q=q->next,i++);/* code */
    printf("��ʾ���˱���%d�����\n",i);
	printf("�������ݣ�\n");
	TraverseList_DuL(p);
	int j,h,f;
	printf("\n");
	printf("��������ţ�\n");
	int choice;
    fflush(stdin);
    scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
		case 1:
		{
			printf("�������½��Ҫ�����ڵڼ������֮ǰ\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("�������ݴ���\n");goto A;
			}
			q=p;
			for(f=1;f<j;f++,q=q->next);
			g=(DuLinkedList)malloc(sizeof(DuLNode));
			g->next=NULL;
			g->prior=NULL;
			printf("�������½������\n");
			scanf("%d",&(g->data));
			InsertBeforeList_DuL(q,g);
			if(j==1)p=g;
			TraverseList_DuL(p);
			system("pause");
			goto A;
		}
        case 2:
		{
			printf("�������½��Ҫ�����ڵڼ������֮��\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("�������ݴ���\n");goto A;
			}
			for(f=1,q=p;f<j;f++,q=q->next);
			g=(DuLinkedList)malloc(sizeof(DuLNode));
			g->next=NULL;
			g->prior=NULL;
			printf("�������½������\n");
			scanf("%d",&(g->data));
			InsertAfterList_DuL(q,g);
			TraverseList_DuL(p);
			system("pause");
			goto A;
		}
		case 3:
		{
			printf("������Ҫ��ѯ������\n");
			scanf("%d",&f);
			q=p;
			for(j=1;q!=NULL;j++,q=q->next)
			{
				if(q->data==f)
				printf("��%d������������%d\n",j,f);
			}
		    system("pause"); 
			goto A;
		}
	    case 4: 
		{
			printf("������Ҫɾ���ڼ������\n");
			scanf("%d",&j);
			if (j<=0||j>i)
			{
				printf("�������ݴ���\n");goto A;
			}
			if(p==NULL||p->next==NULL)
			{
				printf("ֻʣһ����㣬�޷�ִ�д˲���\n");
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
			printf("ɾ�����ǵ�%d����㣬������%d\n",j,f);
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
		printf("������������δ���������������Ͳ�ͬ,�޷����д˲���");
		system("pause");
		return;
	}
	if(n==11)
	{
		MergelinkedList(head1,head2);
		printf("�ϲ�������1\n");
		TraverseList(head1);
		n=10;
		system("pause");
	}
	if(n==22)
	{
		MergelinkedList_Dul(head3, head4);
		printf("�ϲ�������1\n");
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