#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef int Status;
typedef struct BiTNode
{
    char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
Status CreatBiTree(BiTree & T) 
{ 
	char ch;
	scanf("%c",&ch);
	if(ch==' ')
	{
        T=NULL; 
	}
    else
    {
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))
		{
			exit(OVERFLOW);
		}
        T->data=ch;   
		CreatBiTree(T->lchild);      
		CreatBiTree(T->rchild);
    }
    return 1;
}
BiTNode * CreatBiTree()
{
    BiTNode *T;
	char ch;
    scanf("%c",&ch);
	if(ch==' ')
    {
        T=NULL;
    }
    else
    {
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;     
		T->lchild=CreatBiTree();       
		T->rchild=CreatBiTree();
    }
    return T;
}
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}
void DestoryBiTree(BiTree *T) 
{
	if(*T!= NULL)
	{
		DestoryBiTree(&((*T)->lchild));
		DestoryBiTree(&((*T)->rchild));
		free(*T);
		*T= NULL;
	}
}
void main(){
	BiTree T= NULL;
	CreatBiTree(T);
	cout<<"中序遍历结果是:"<<endl;
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"中序遍历结果是:"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	cout<<"中序遍历结果是:"<<endl;
	PostOrderTraverse(T);
	cout<<endl;
	DestoryBiTree(&T);
	system("pause");
}