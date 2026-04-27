#include<bits/stdc++.h>
using namespace std;
int cost(int a,int b){
    if(a==b)return 1;
    if(a==0)return 2;
    if(abs(a-b)==2)return 4;
    return 3;
}
int dp[100001][5][5];
int main(){
    vector<int>seq;
    int x;while(cin>>x&&x)seq.push_back(x);
    int n=seq.size();
    for(auto&a:dp)for(auto&b:a)fill(b,b+5,1e9);
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        int t=seq[i];
        for(int l=0;l<5;l++)for(int r=0;r<5;r++){
            if(dp[i][l][r]==1e9)continue;
            if(t!=r)dp[i+1][t][r]=min(dp[i+1][t][r],dp[i][l][r]+cost(l,t));
            if(t!=l)dp[i+1][l][t]=min(dp[i+1][l][t],dp[i][l][r]+cost(r,t));
        }
    }
    int ans=1e9;
    for(int l=0;l<5;l++)for(int r=0;r<5;r++)ans=min(ans,dp[n][l][r]);
    cout<<ans;
}