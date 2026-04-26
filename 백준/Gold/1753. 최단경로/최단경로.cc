#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e9;
int main(){
    int v,e;cin>>v>>e;
    int k;cin>>k;
    vector<vector<pii>> g(v+1);
    for(int i=0;i<e;i++){int a,b,c;cin>>a>>b>>c;g[a].push_back({b,c});}
    vector<int>d(v+1,INF);
    priority_queue<pii,vector<pii>,greater<>> pq;
    d[k]=0;pq.push({0,k});
    while(!pq.empty()){
        auto[dd,u]=pq.top();pq.pop();
        if(dd>d[u])continue;
        for(auto[nv,w]:g[u])if(d[u]+w<d[nv]){d[nv]=d[u]+w;pq.push({d[nv],nv});}
    }
    for(int i=1;i<=v;i++)cout<<(d[i]==INF?"INF":to_string(d[i]))<<"\n";
}