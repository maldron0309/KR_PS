#include<bits/stdc++.h>
using namespace std;
int p[51];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void unite(int a,int b){p[find(a)]=find(b);}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)p[i]=i;
    int k;cin>>k;
    vector<int> truth(k);
    for(int i=0;i<k;i++){cin>>truth[i];unite(truth[i],0);}
    vector<vector<int>> party(m);
    for(int i=0;i<m;i++){
        int cnt;cin>>cnt;
        party[i].resize(cnt);
        for(int j=0;j<cnt;j++)cin>>party[i][j];
        for(int j=1;j<cnt;j++)unite(party[i][0],party[i][j]);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        bool ok=true;
        for(int x:party[i])if(find(x)==find(0)){ok=false;break;}
        if(ok)ans++;
    }
    cout<<ans;
}