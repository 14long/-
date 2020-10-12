#include <bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2)
{
    return a1>a2;
}
struct node{
    int u;
    int v;
    int w;
 /*   friend bool operator<(const node &a1,const node &a2)
    {
        return a1.u>a2.u;//相反
    }*/
    bool operator<(node a1)const
    {
        return u>a1.u;
    }
}dian[100];
int s1[100];
bool cmp2(const node &a1,const node &a2)
{
    if(a1.u==a2.u) return a1.w>a2.w;//降序
    return a1.u<a2.u;//升序
}
bool cmp4(const node &a1,const node &a2)
{
    return a1.u>a2.u;
}
bool cmp3(const int a1,const int a2)
{
    return a1>=a2;
}
priority_queue<node> k1;

int main()
{
    dian[1].u=10;
    dian[1].w=3;
    dian[2].u=19;
    dian[2].w=7;
    dian[3].u=10;
    dian[3].w=4;
    dian[4].u=4;
    dian[4].w=4;
    sort(dian+1,dian+1+4,cmp2);
    for(int i=1;i<=4;i++) cout<<dian[i].w<<' '<<dian[i].u<<endl;
    s1[1]=10,s1[2]=3,s1[3]=15,s1[4]=7,s1[5]=9;
    sort(s1+1,s1+1+5);
    for(int i=1;i<=5;i++) cout<<s1[i]<<' ';
    cout<<endl;
    sort(s1+1,s1+1+5,cmp);
    for(int i=1;i<=5;i++) cout<<s1[i]<<' ';
    cout<<endl;
    s1[6]=10;
    sort(s1+1,s1+1+6,cmp3);
    for(int i=1;i<=5;i++) cout<<s1[i]<<' ';
    cout<<endl;
    sort(s1+1,s1+1+6,cmp);
    for(int i=1;i<=5;i++) cout<<s1[i]<<' ';
    cout<<endl;


    sort(dian+1,dian+1+4,cmp4);
    for(int i=1;i<=4;i++)
    {
        cout<<dian[i].u<<' ';
    }
    cout<<endl;
    k1.push(dian[1]);
    k1.push(dian[2]);
    k1.push(dian[3]);
    k1.push(dian[4]);
    while(!k1.empty())
    {
        node q=k1.top();
        k1.pop();
        cout<<q.u<<endl;
    }

    return 0;
}