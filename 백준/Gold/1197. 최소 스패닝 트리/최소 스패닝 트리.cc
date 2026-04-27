#include<bits/stdc++.h>
using namespace std;
int p[10001];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
    int v,e;cin>>v>>e;
    vector<tuple<int,int,int>>edges(e);
    for(auto&[c,a,b]:edges)cin>>a>>b>>c;
    sort(edges.begin(),edges.end());
    iota(p,p+v+1,0);
    long long ans=0;
    for(auto[c,a,b]:edges){
        int pa=find(a),pb=find(b);
        if(pa!=pb){p[pa]=pb;ans+=c;}
    }
    cout<<ans;
}