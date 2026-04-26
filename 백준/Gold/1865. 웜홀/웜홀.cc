#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,m,w;cin>>n>>m>>w;
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<m;i++){int a,b,c;cin>>a>>b>>c;edges.push_back({a,b,c});edges.push_back({b,a,c});}
        for(int i=0;i<w;i++){int a,b,c;cin>>a>>b>>c;edges.push_back({a,b,-c});}
        vector<int>d(n+1,0);
        bool neg=false;
        for(int i=0;i<n;i++){
            for(auto[u,v,w2]:edges){
                if(d[u]+w2<d[v]){d[v]=d[u]+w2;if(i==n-1)neg=true;}
            }
        }
        cout<<(neg?"YES":"NO")<<"\n";
    }
}