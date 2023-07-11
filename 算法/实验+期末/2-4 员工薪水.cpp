#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int needed[13];
int n;
int hire,sal,fire;
int dp[13][1111];   //dp[i][j]��ʾ��i������j��Ա����ְ��״̬����С����
int main()
{
    cin.sync_with_stdio(false);

    while (cin>>n,n!=0)
    {
        int mmax(0);    //mmax��¼�����·�����Ҫ������Ա��
        cin>>hire>>sal>>fire;
        needed[0]=0;
        
        for (int i=1;i<=n;i++)
        {
            cin>>needed[i];
            mmax=max(mmax,needed[i]);
        }
        dp[0][0]=0;//��ʼ��������0Ա������״̬���Ƿ�(��ʼ�����Էŵ������ʼ��)
        
        for (int i=1;i<=mmax;i++)
            dp[0][i]=99999999;

        for (int i=1;i<=n;i++)
        {
            /*
            for (int j=0;j<needed[i];j++)   //��С����С����������״̬���Ϊ�Ƿ�
            {                               //������״̬ת��ʱע��߽磬�����Ƿ�����Ҳ����
                dp[i][j]=99999999;
            }*/
            for (int j=needed[i];j<=mmax;j++)
            {
                dp[i][j]=99999999;
                for (int k=needed[i-1];k<=mmax;k++)
                {
                    int temp;   //��¼Ա���仯��ɵĿ���
                    temp = k>j ? fire * (k-j) : hire * (j-k);   //k>jʱ�ǲ�Ա
                    dp[i][j]=min(dp[i][j],dp[i-1][k] + temp);
                }
                dp[i][j]+=j*sal;    //���ϸ���нˮ
            }
        }
        int result=99999999;
        for (int i=needed[n];i<=mmax;i++)
            result=min(result,dp[n][i]);
        cout<<result<<endl;
    }
    return 0;
}
