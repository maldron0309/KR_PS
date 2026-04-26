#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e9;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<pii>> g(n+1);
    for(int i=0;i<m;i++){int a,b,c;cin>>a>>b>>c;g[a].push_back({b,c});}
    int s,t;cin>>s>>t;
    vector<int>d(n+1,INF);
    priority_queue<pii,vector<pii>,greater<>> pq;
    d[s]=0;pq.push({0,s});
    while(!pq.empty()){
        auto[dd,u]=pq.top();pq.pop();
        if(dd>d[u])continue;
        for(auto[v,w]:g[u])if(d[u]+w<d[v]){d[v]=d[u]+w;pq.push({d[v],v});}
    }
    cout<<d[t];
}