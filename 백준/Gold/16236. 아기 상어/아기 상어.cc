#include<bits/stdc++.h>
using namespace std;
int n,g[21][21];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int main(){
    cin>>n;
    int sx,sy,sz=2,ate=0,ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){cin>>g[i][j];if(g[i][j]==9){sx=i;sy=j;g[i][j]=0;}}
    while(true){
        vector<vector<int>> d(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        d[sx][sy]=0;q.push({sx,sy});
        pair<int,int> target={-1,-1};int td=1e9;
        while(!q.empty()){
            auto[x,y]=q.front();q.pop();
            if(d[x][y]>td)break;
            if(g[x][y]&&g[x][y]<sz){
                if(d[x][y]<td||(d[x][y]==td&&(x<target.first||(x==target.first&&y<target.second)))){td=d[x][y];target={x,y};}
            }
            for(int dd=0;dd<4;dd++){int nx=x+dx[dd],ny=y+dy[dd];
                if(nx<0||nx>=n||ny<0||ny>=n||d[nx][ny]!=-1||g[nx][ny]>sz)continue;
                d[nx][ny]=d[x][y]+1;q.push({nx,ny});}
        }
        if(target.first==-1)break;
        ans+=td;sx=target.first;sy=target.second;
        g[sx][sy]=0;ate++;if(ate==sz){sz++;ate=0;}
    }
    cout<<ans;
}