#include<bits/stdc++.h>
using namespace std;
int n,m,g[1001][1001],grp[1001][1001],gsz[1000001];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){char c;cin>>c;g[i][j]=c-'0';}
    int gid=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(g[i][j]==0&&!grp[i][j]){
            gid++;int cnt=0;
            queue<pair<int,int>>q;q.push({i,j});grp[i][j]=gid;
            while(!q.empty()){auto[x,y]=q.front();q.pop();cnt++;
                for(int d=0;d<4;d++){int nx=x+dx[d],ny=y+dy[d];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]==0&&!grp[nx][ny]){grp[nx][ny]=gid;q.push({nx,ny});}}}
            gsz[gid]=cnt;
        }
    }
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(!g[i][j]){cout<<0;continue;}
        set<int>seen;int s=1;
        for(int d=0;d<4;d++){int nx=i+dx[d],ny=j+dy[d];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!g[nx][ny]&&!seen.count(grp[nx][ny])){seen.insert(grp[nx][ny]);s+=gsz[grp[nx][ny]];}}
        cout<<s%10;}cout<<"\n";}
}