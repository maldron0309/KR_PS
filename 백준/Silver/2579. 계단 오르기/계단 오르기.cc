#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    vector<int> dp(n+1,0);
    dp[1]=s[1];
    if(n>=2) dp[2]=s[1]+s[2];
    for(int i=3;i<=n;i++)
        dp[i]=max(dp[i-2]+s[i], dp[i-3]+s[i-1]+s[i]);
    cout<<dp[n];
}