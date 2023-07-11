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
	cout<<"请输入元素"<<endl;
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
	cout<<"请输入链表的个数："<<endl;
	scanf("%d",&n);
	CreateList_L(L,n);
	cout<<"原来的链表数据为："<<endl;
	p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
    Contray_List(L);
	p=L->next;
	cout<<"逆置后的链表数据为："<<endl;
    while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	free(L);
}

		
