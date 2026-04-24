#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        map<string,int> m;
        for(int i=0;i<n;i++) { string a,b; cin>>a>>b; m[b]++; }
        long long ans=1;
        for(auto& [k,v]:m) ans*=(v+1);
        cout<<ans-1<<"\n";
    }
}