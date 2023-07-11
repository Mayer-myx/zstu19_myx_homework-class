#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node
{
    int l,w;

}a[5005];

bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].l,&a[i].w);
        sort(a,a+n,cmp);
        int flag,ans=1,x[5005],y[5005];
        x[0]=a[0].l,y[0]=a[0].w;
        for(int i=1;i<n;i++)
        {
            flag=0;
            for(int j=0;j<ans;j++)
            {
                if(a[i].l>=x[j]&&a[i].w>=y[j])
                {
                    x[j]=a[i].l,y[j]=a[i].w;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                x[ans]=a[i].l,y[ans]=a[i].w;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
