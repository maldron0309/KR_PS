#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1e9;
vector<pair<int,int>> houses,chickens,chosen;
void bt(int s,int k){
    if(k==m){
        int tot=0;
        for(auto[hx,hy]:houses){int mn=1e9;for(auto[cx,cy]:chosen)mn=min(mn,abs(hx-cx)+abs(hy-cy));tot+=mn;}
        ans=min(ans,tot);return;
    }
    for(int i=s;i<(int)chickens.size();i++){chosen.push_back(chickens[i]);bt(i+1,k+1);chosen.pop_back();}
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){int x;cin>>x;if(x==1)houses.push_back({i,j});else if(x==2)chickens.push_back({i,j});}
    bt(0,0);cout<<ans;
}