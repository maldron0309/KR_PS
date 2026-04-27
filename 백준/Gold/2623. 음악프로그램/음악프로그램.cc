#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int>indeg(n+1,0);
    for(int i=0;i<m;i++){
        int k;cin>>k;vector<int>order(k);for(int&x:order)cin>>x;
        for(int j=1;j<k;j++){g[order[j-1]].push_back(order[j]);indeg[order[j]]++;}
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(!indeg[i])q.push(i);
    vector<int>res;
    while(!q.empty()){int u=q.front();q.pop();res.push_back(u);for(int v:g[u])if(--indeg[v]==0)q.push(v);}
    if((int)res.size()!=n)cout<<0;
    else for(int x:res)cout<<x<<"\n";
}