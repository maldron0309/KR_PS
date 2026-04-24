#include <bits/stdc++.h>
using namespace std;
int main() {
    int K,N; cin>>K>>N;
    vector<long long> v(K);
    for (auto& x:v) cin>>x;
    long long lo=1, hi=*max_element(v.begin(),v.end());
    while (lo<hi) {
        long long mid=(lo+hi+1)/2;
        long long cnt=0; for (auto x:v) cnt+=x/mid;
        if (cnt>=N) lo=mid; else hi=mid-1;
    }
    cout<<lo;
}