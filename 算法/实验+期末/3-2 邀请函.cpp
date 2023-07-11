#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

static const int MAXN=1000000;
int x[MAXN+10],y[MAXN+10],z[MAXN+10];
struct Node{
    int v,c;
    Node(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator < (const Node &r) const {
        return c>r.c;
    }
};

struct Edge{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector<Edge> E[MAXN+10];
bool vis[MAXN+10];
int dist[MAXN+10];

void dijkstra(int n,int start)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    priority_queue<Node> Q;
    dist[start]=0;
    Q.push(Node(start,0));
    while(!Q.empty())
    {
        Node tmp=Q.top();
        Q.pop();
        int u=tmp.v;
        if(vis[u])
            continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            int cost=E[u][i].cost;
            if(!vis[v] && dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                Q.push(Node(v,dist[v]));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        for(int i=1;i<=p;i++)
            E[i].clear();
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            E[x[i]].push_back(Edge(y[i],z[i]));
        }
        dijkstra(p,1);
        long long ans=0;
        for(int i=1;i<=p;i++)
            ans+=dist[i];
        for(int i=1;i<=p;i++)
            E[i].clear();
        for(int i=1;i<=q;i++)
            E[y[i]].push_back(Edge(x[i],z[i]));
        dijkstra(p,1);
        for(int i=1;i<=p;i++)
            ans+=dist[i];
        printf("%lld\n",ans);
    }
    return 0;
}
