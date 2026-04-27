#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;cin>>t;
    int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;
    int m;cin>>m;vector<int>b(m);for(int&x:b)cin>>x;
    vector<long long>sa,sb;
    for(int i=0;i<n;i++){long long s=0;for(int j=i;j<n;j++){s+=a[j];sa.push_back(s);}}
    for(int i=0;i<m;i++){long long s=0;for(int j=i;j<m;j++){s+=b[j];sb.push_back(s);}}
    sort(sb.begin(),sb.end());
    long long ans=0;
    for(long long x:sa){
        auto lo=lower_bound(sb.begin(),sb.end(),t-x);
        auto hi=upper_bound(sb.begin(),sb.end(),t-x);
        ans+=hi-lo;
    }
    cout<<ans;
}