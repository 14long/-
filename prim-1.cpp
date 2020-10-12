#include <bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxm=1e7+7;////
int n,m;
int map1[maxn][maxn];
int lco[maxn];
int mst[maxn];
void input()
{
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        map1[a1][a2]=a3;
        map1[a2][a1]=a3;
    }
}
void pre()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                map1[i][j]=0;
            }
            else
            {
                map1[i][j]=maxm;
            }
        }
    }
    ////
    
}
void prim(int u)
{
    int ans=0;
    for(int i=1;i<=n;i++)//not m
    {
        lco[i]=map1[u][i];
        mst[i]=u;
    }
    mst[u]=-1;


    for(int i=1;i<n;i++)
    {
        int v1=-1;
        int low=maxm;
        for(int i=1;i<=n;i++)
        {
            if(mst[i]!=-1&&lco[i]<low)
            {
                v1=i;
                low=lco[i];
            }
        }

        //
        mst[v1]=-1;
        ans+=lco[v1];
        for(int j=1;j<=n;j++)
        {
            if(mst[j]!=-1&&lco[j]>map1[v1][j])
            {
                lco[j]=map1[v1][j];
                mst[j]=v1;
            }
        }

    }

    cout<<ans<<endl;

}
int main()
{
    cin>>n>>m;
    pre();
    input();
    prim(1);
    return 0;
}