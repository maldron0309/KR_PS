#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll pw(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%MOD;a=a*a%MOD;}return r;}
int main(){
    int m;cin>>m;
    ll ans=0;
    while(m--){ll n,s;cin>>n>>s;ans=(ans+s%MOD*pw(n,MOD-2))%MOD;}
    cout<<ans;
}