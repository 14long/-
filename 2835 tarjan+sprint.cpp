#include <bits/stdc++.h>
using namespace std;
const int maxn=201;
int cnt=0,n,m,tot=0;
int d[maxn],l[maxn];
bool vis[maxn];
int sp[maxn];
int rd[maxn];
vector<int> u[maxn];
stack<int> k;
void pre()
{
    for(int i=0;i<maxn;i++)
    {
        d[i]=l[i]=rd[i]=sp[i]=0;
        vis[i]=0;
    }
}
void input()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int a1;
            cin>>a1;
            if(!a1) break;
            else 
            {
                u[i].push_back(a1);
            }
        }
    }
}
void tarjan(int now)
{
    d[now]=l[now]=++cnt;
    k.push(now);
    vis[now]=1;
    for(int i=0;i<u[now].size();i++)
    {
        int v=u[now][i];
        if(!d[v])
        {
            tarjan(v);
            l[now]=min(l[now],l[v]);
        }
        else if(vis[v])
        {
            l[now]=min(l[now],d[v]);
        }
    }

    if(d[now]==l[now])
    {
        tot++;
        while(!k.empty())
        {
            int a1=k.top();
            k.pop();
            if(now==a1)
            {
                sp[a1]=tot;
                vis[a1]=0;
                break;
            }
            else
            {
                sp[a1]=tot;
                vis[a1]=0;////
            }
        }
    }
}
void sprint()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<u[i].size();j++)
        {
            int v=u[i][j];
            if(sp[v]!=sp[i])
            {
                rd[sp[v]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=tot;i++)
    {
        if(!rd[i]) ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    pre();
    input();
    for(int i=1;i<=n;i++)
        if(!d[i]) tarjan(i);
    sprint();
    return 0;
}