#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100001];
int dist[100001];
void bfs(int s,int n){
    fill(dist,dist+n+1,-1);
    queue<int>q;
    q.push(s);dist[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto[v,w]:g[u])if(dist[v]==-1){dist[v]=dist[u]+w;q.push(v);}
    }
}
int main(){
    int v;cin>>v;
    for(int i=0;i<v;i++){
        int u;cin>>u;
        while(true){int a;cin>>a;if(a==-1)break;int b;cin>>b;g[u].push_back({a,b});}
    }
    bfs(1,v);
    int far=max_element(dist,dist+v+1)-dist;
    bfs(far,v);
    cout<<*max_element(dist,dist+v+1);
}