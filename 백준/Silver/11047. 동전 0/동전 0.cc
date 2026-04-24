#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; long long K; cin>>N>>K;
    vector<long long> a(N); for(auto& x:a) cin>>x;
    int cnt=0;
    for(int i=N-1;i>=0;i--) { cnt+=K/a[i]; K%=a[i]; }
    cout<<cnt;
}