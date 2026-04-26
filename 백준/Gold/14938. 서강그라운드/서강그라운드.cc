#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int d[101][101],t[101];
int main(){
    int n,m,r;cin>>n>>m>>r;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=i==j?0:INF;
    for(int i=0;i<r;i++){int a,b,l;cin>>a>>b>>l;d[a][b]=min(d[a][b],l);d[b][a]=min(d[b][a],l);}
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if(d[i][k]<INF&&d[k][j]<INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int ans=0;
    for(int i=1;i<=n;i++){int s=0;for(int j=1;j<=n;j++)if(d[i][j]<=m)s+=t[j];ans=max(ans,s);}
    cout<<ans;
}