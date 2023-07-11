#include <stdio.h>

struct Matrix

{
	int m[2][2];
};

Matrix mul(Matrix a,Matrix b)

{
	Matrix ans;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{     
			ans.m[i][j] = 0;
			for(int k = 0; k < 2; k++)
			{
				ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j] % 7) % 7;
			}
		}
	}
	return ans;
}

int main()
{
	int A,B,n;
	while(scanf("%d%d%d",&A,&B,&n) != EOF)
	{
		if(A == 0 && B == 0 && n == 0) break;
		if(n==2||n==1)
		{
			printf("1\n");
			continue;
		}

		Matrix a,ans;
		a.m[0][0] = A;
		a.m[0][1] = B;
		a.m[1][0] = 1;
		a.m[1][1] = 0;
		ans.m[0][0] = ans.m[1][1] = 1;
		ans.m[0][1] = ans.m[1][0] = 0;
		n -= 2;

		while(n)
		{
			if(n & 1)
			{
				ans = mul(ans,a);
			}
			n >>= 1;
			a = mul(a,a);
		}
		printf("%d\n",(ans.m[0][0] + ans.m[0][1]) % 7);
	}
	return 0;
}
