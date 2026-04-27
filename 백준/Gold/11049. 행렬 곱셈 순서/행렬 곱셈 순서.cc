#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>r(n),c(n);
    for(int i=0;i<n;i++)cin>>r[i]>>c[i];
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    for(int len=2;len<=n;len++)for(int i=0;i+len-1<n;i++){
        int j=i+len-1;dp[i][j]=1e18;
        for(int k=i;k<j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(long long)r[i]*c[k]*c[j]);
    }
    cout<<dp[0][n-1];
}