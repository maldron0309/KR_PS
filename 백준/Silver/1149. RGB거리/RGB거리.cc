#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<array<int,3>> dp(n);
    for(int i=0;i<n;i++)cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
    for(int i=1;i<n;i++){
        dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]+=min(dp[i-1][0],dp[i-1][1]);
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}