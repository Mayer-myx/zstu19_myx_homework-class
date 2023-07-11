#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	int score;
	string name;
}Student;
void Swap(int i,int p)
{        
	ElemType tmp=data[i];        
	data[i]=data[p];        
	data[p]=tmp;
}
int Partition1(SqList *L,int low,int high)
{
	int pivotkey;
	int m=low+(high-low)/2;
	if(L->r[low]>L->r[high])
		swap(L,low,high);
	if(L->r[m]>L->r[high])
		swap(L,high,m);
	if(L->r[m]>L->r[low])
		swap(L,m,low);
	    pivotkey=L->r[low];
    L->r[0]=pivotkey;
	while(low<high)
	{
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low;
}
void QSort(SqList *L,int low,int high )
{
	int pivot;
	if(low<high)
	{
		pivat=Partition(L,low,high);
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
}
void Quicksort(SqList *L)
{
	QSort(L,1,L->length);
}
int main()
{

