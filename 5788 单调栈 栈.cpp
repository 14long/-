#include <bits/stdc++.h>
using namespace std;
stack<int> xushu;
int a[4000000]={0};
int fn[4000000]={0};
void dandiaozhan(int all);
int main(){
    ios::sync_with_stdio(false);//输入输出流
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i+1];//scanf("%d",&a[i+1]);
    dandiaozhan(n);
    for(int i=1;i<=n;i++) cout<<fn[i]<<' ';//printf("%d ",fn[i]);
    return 0;
}
void dandiaozhan(int all){
    xushu.push(1);
    for(int i=2;i<=all;i++){
        while(1){
            if(a[i]<=a[xushu.top()]) break;
            fn[xushu.top()]=i;
           // cout<<fn[xushu.top()]<<endl;
            xushu.pop();
          //  cout<<xushu.size()<<endl;
            if(xushu.empty()) break;
        }
        xushu.push(i);//cout<<xushu.size()<<endl;
    }
    return;
}


/*
9 4 13 9 4
1 2 3 4 5
*/