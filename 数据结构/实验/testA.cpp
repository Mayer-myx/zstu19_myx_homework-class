#include <stdlib.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>

#define LIST_INIT_LENGTM 10
#define OK 1
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
void CreateList_L(LinkList &L,int n)
{
	int i;
	LNode *p;
	int array[LIST_INIT_LENGTM ];
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cout<<"������Ԫ��"<<endl;
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	for(i=n-1;i>=0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->data=array[i];
		p->next=L->next;
		L->next=p;
	}
}
int Contray_List(LinkList &L)
{
	LinkList p,q;
	p=L->next;
	L->next=NULL;
	while(p)
	{
	q=(LinkList)malloc(sizeof(LNode));
	q->data=p->data;
	q->next=L->next;
	L->next=q;
	p=p->next;
	}
	return OK;
}
void main()
{
    LinkList L,p;
	int n;
	cout<<"����������ĸ�����"<<endl;
	scanf("%d",&n);
	CreateList_L(L,n);
	cout<<"ԭ������������Ϊ��"<<endl;
	p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
    Contray_List(L);
	p=L->next;
	cout<<"���ú����������Ϊ��"<<endl;
    while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	free(L);
}

		
