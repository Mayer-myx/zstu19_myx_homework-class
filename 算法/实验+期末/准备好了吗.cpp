# include<cstdio>
# include<iostream>
# include<algorithm>
using namespace std;
 
struct ID
{
    int Ti,Si,Pi;
};ID id[1000];
 
int cmp(ID n,ID m)
{
    if(n.Pi!=m.Pi)   return n.Pi>m.Pi;
    else   return n.Si>m.Si;
}
 
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int i,n,flag=1;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>id[i].Ti>>id[i].Si>>id[i].Pi;
        sort(id,id+n,cmp);
        for(i=0;i<n;i++)
        {
            if(flag)
            {
                cout<<id[i].Ti;
                flag=0;
            }
            else       cout<<' '<<id[i].Ti;
        }
        if(c!=0) cout<<endl;
    }
    return 0;
}
