#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,M; cin>>N>>M;
    vector<long long> pre(N+1,0);
    for(int i=1;i<=N;i++) { int x; cin>>x; pre[i]=pre[i-1]+x; }
    while(M--) { int i,j; cin>>i>>j; cout<<pre[j]-pre[i-1]<<"\n"; }
}