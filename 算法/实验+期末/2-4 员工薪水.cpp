#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int needed[13];
int n;
int hire,sal,fire;
int dp[13][1111];   //dp[i][j]表示第i个月有j个员工在职的状态的最小消耗
int main()
{
    cin.sync_with_stdio(false);

    while (cin>>n,n!=0)
    {
        int mmax(0);    //mmax记录所有月份中需要的最多的员工
        cin>>hire>>sal>>fire;
        needed[0]=0;
        
        for (int i=1;i<=n;i++)
        {
            cin>>needed[i];
            mmax=max(mmax,needed[i]);
        }
        dp[0][0]=0;//初始化，除了0员工其他状态都非法(初始化可以放到程序最开始处)
        
        for (int i=1;i<=mmax;i++)
            dp[0][i]=99999999;

        for (int i=1;i<=n;i++)
        {
            /*
            for (int j=0;j<needed[i];j++)   //把小于最小工作人数的状态标记为非法
            {                               //或者在状态转移时注意边界，跳过非法部分也可以
                dp[i][j]=99999999;
            }*/
            for (int j=needed[i];j<=mmax;j++)
            {
                dp[i][j]=99999999;
                for (int k=needed[i-1];k<=mmax;k++)
                {
                    int temp;   //记录员工变化造成的开销
                    temp = k>j ? fire * (k-j) : hire * (j-k);   //k>j时是裁员
                    dp[i][j]=min(dp[i][j],dp[i-1][k] + temp);
                }
                dp[i][j]+=j*sal;    //加上该月薪水
            }
        }
        int result=99999999;
        for (int i=needed[n];i<=mmax;i++)
            result=min(result,dp[n][i]);
        cout<<result<<endl;
    }
    return 0;
}
