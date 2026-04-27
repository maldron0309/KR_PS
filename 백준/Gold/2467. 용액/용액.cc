#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<long long>a(n);for(auto&x:a)cin>>x;
    int l=0,r=n-1;
    long long best=2e18;
    pair<long long,long long>ans;
    while(l<r){
        long long s=a[l]+a[r];
        if(abs(s)<best){best=abs(s);ans={a[l],a[r]};}
        if(s<0)l++;else r--;
    }
    cout<<ans.first<<" "<<ans.second;
}