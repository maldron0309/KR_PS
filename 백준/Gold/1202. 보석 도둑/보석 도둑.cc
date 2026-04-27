#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,k;cin>>n>>k;
    vector<pair<int,int>>jewels(n);
    for(auto&[m,v]:jewels)cin>>m>>v;
    vector<int>bags(k);
    for(int&x:bags)cin>>x;
    sort(jewels.begin(),jewels.end());
    sort(bags.begin(),bags.end());
    priority_queue<int>pq;
    long long ans=0;int j=0;
    for(int b:bags){
        while(j<n&&jewels[j].first<=b)pq.push(jewels[j++].second);
        if(!pq.empty()){ans+=pq.top();pq.pop();}
    }
    cout<<ans;
}