#include<bits/stdc++.h>
using namespace std;
int n,m,g[8][8],ans;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void spread(int tmp[8][8]){
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(tmp[i][j]==2)q.push({i,j});
    while(!q.empty()){
        auto[x,y]=q.front();q.pop();
        for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m||tmp[nx][ny])continue;
            tmp[nx][ny]=2;q.push({nx,ny});}
    }
    int cnt=0;for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!tmp[i][j])cnt++;
    ans=max(ans,cnt);
}
void bt(int k,int si){
    if(k==3){int tmp[8][8];for(int i=0;i<n;i++)for(int j=0;j<m;j++)tmp[i][j]=g[i][j];spread(tmp);return;}
    for(int i=si;i<n*m;i++){int x=i/m,y=i%m;if(g[x][y])continue;g[x][y]=1;bt(k+1,i+1);g[x][y]=0;}
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>g[i][j];
    bt(0,0);cout<<ans;
}