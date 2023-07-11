#include<stdio.h>

int main()
{
	int i,j,T,t1,t2,n,m1,m2;
	scanf("%d",&T);
	while(T--)
	{
		int time=0; 
		int a[625]={0};
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&m1,&m2);
			t2=m1>m2?m1:m2;
			t1=m1<m2?m1:m2;
			for(i=(t1+1)/2;i<=(t2+1)/2;i++)
				a[i]++;                       
		}
		for(i=1;i<=400;i++)
			if(a[i]>time)  time=a[i];         
			printf("%d\n",time*10);
	}
	return 0;
}
