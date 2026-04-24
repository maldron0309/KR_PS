#include <bits/stdc++.h>
using namespace std;
int grid[50][50];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
void bfs(int x, int y, int M, int N) {
    queue<pair<int,int>> q;
    q.push({x,y}); grid[x][y]=0;
    while (!q.empty()) {
        auto [cx,cy] = q.front(); q.pop();
        for (int d=0;d<4;d++) {
            int nx=cx+dx[d], ny=cy+dy[d];
            if (nx>=0&&nx<N&&ny>=0&&ny<M&&grid[nx][ny]) { grid[nx][ny]=0; q.push({nx,ny}); }
        }
    }
}
int main() {
    int T; cin >> T;
    while (T--) {
        int M,N,K; cin>>M>>N>>K;
        memset(grid,0,sizeof(grid));
        for (int i=0;i<K;i++) { int x,y; cin>>x>>y; grid[y][x]=1; }
        int cnt=0;
        for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (grid[i][j]) { bfs(i,j,M,N); cnt++; }
        cout << cnt << "\n";
    }
}