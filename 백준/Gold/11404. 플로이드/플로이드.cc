#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int d[101][101];
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=i==j?0:INF;
    for(int i=0;i<m;i++){int a,b,c;cin>>a>>b>>c;d[a][b]=min(d[a][b],c);}
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if(d[i][k]<INF&&d[k][j]<INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<(d[i][j]==INF?0:d[i][j])<<" ";cout<<"\n";}
}