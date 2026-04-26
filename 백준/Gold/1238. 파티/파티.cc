#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e9;
int main(){
    int n,m,x;cin>>n>>m>>x;
    vector<vector<pii>> g(n+1),rg(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        rg[b].push_back({a,c});
    }
    auto dijk=[&](int s,vector<vector<pii>>&gr){
        vector<int>d(n+1,INF);
        priority_queue<pii,vector<pii>,greater<>> pq;
        d[s]=0;pq.push({0,s});
        while(!pq.empty()){
            auto[dd,u]=pq.top();pq.pop();
            if(dd>d[u])continue;
            for(auto[v,w]:gr[u])if(d[u]+w<d[v]){d[v]=d[u]+w;pq.push({d[v],v});}
        }
        return d;
    };
    auto dx=dijk(x,rg);
    auto fx=dijk(x,g);
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dx[i]+fx[i]);
    cout<<ans;
}