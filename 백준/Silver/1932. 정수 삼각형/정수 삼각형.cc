#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++){dp[i].resize(i+1);for(int j=0;j<=i;j++)cin>>dp[i][j];}
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            int a=j>0?dp[i-1][j-1]:-1;
            int b=j<i?dp[i-1][j]:-1;
            dp[i][j]+=max(a,b);
        }
    }
    cout<<*max_element(dp[n-1].begin(),dp[n-1].end());
}