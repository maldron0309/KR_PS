#include <bits/stdc++.h>
using namespace std;
int g[25][25],N;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int bfs(int x,int y) {
    queue<pair<int,int>> q; q.push({x,y}); g[x][y]=0; int cnt=1;
    while(!q.empty()) { auto[cx,cy]=q.front(); q.pop(); for(int d=0;d<4;d++) { int nx=cx+dx[d],ny=cy+dy[d]; if(nx>=0&&nx<N&&ny>=0&&ny<N&&g[nx][ny]) { g[nx][ny]=0; cnt++; q.push({nx,ny}); } } }
    return cnt;
}
int main() {
    cin>>N;
    for(int i=0;i<N;i++) { string s; cin>>s; for(int j=0;j<N;j++) g[i][j]=s[j]-'0'; }
    vector<int> res;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(g[i][j]) res.push_back(bfs(i,j));
    sort(res.begin(),res.end());
    cout<<res.size()<<"\n"; for(int x:res) cout<<x<<"\n";
}