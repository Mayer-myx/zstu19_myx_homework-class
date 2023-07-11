#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

char a[1010],b[1010];
int dp[1010][1010];
int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int i,j,c1,c2;
    while(cin>>a>>b)
    {
        c1=strlen(a);
        c2=strlen(b);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=c1;i++)
            for(j=1;j<=c2;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[c1][c2]<<endl;
    }
    return 0;
}
//��ȡa���еĵ�һ���ַ���b���е�ǰһ����������ֱ��������Ƚϣ�����ͬ����ͬ���ַ���+1���˺��Դ�������a�����е��ַ����Ƚ��ꡣ
//dp���̣�dp[i][j]=max(dp[i-1][j],dp[i][j-1])

