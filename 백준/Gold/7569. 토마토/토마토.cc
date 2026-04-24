#include <bits/stdc++.h>
using namespace std;
int main() {
    int M,N,H; cin>>M>>N>>H;
    vector<vector<vector<int>>> g(H,vector<vector<int>>(N,vector<int>(M)));
    queue<tuple<int,int,int>> q;
    for(int h=0;h<H;h++) for(int i=0;i<N;i++) for(int j=0;j<M;j++) { cin>>g[h][i][j]; if(g[h][i][j]==1) q.push({h,i,j}); }
    int dh[]={0,0,0,0,1,-1}, di[]={0,0,1,-1,0,0}, dj[]={1,-1,0,0,0,0};
    while(!q.empty()) {
        auto[h,i,j]=q.front(); q.pop();
        for(int d=0;d<6;d++) { int nh=h+dh[d],ni=i+di[d],nj=j+dj[d]; if(nh>=0&&nh<H&&ni>=0&&ni<N&&nj>=0&&nj<M&&g[nh][ni][nj]==0) { g[nh][ni][nj]=g[h][i][j]+1; q.push({nh,ni,nj}); } }
    }
    int ans=0;
    for(int h=0;h<H;h++) for(int i=0;i<N;i++) for(int j=0;j<M;j++) { if(g[h][i][j]==0) { cout<<-1; return 0; } ans=max(ans,g[h][i][j]); }
    cout<<ans-1;
}