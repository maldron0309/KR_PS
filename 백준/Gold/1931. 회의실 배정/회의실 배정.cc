#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin>>N;
    vector<pair<int,int>> v(N);
    for (auto& [s,e]:v) cin>>s>>e;
    sort(v.begin(),v.end(),[](auto& a,auto& b){ return a.second!=b.second?a.second<b.second:a.first<b.first; });
    int cnt=0, end=0;
    for (auto& [s,e]:v) if (s>=end) { cnt++; end=e; }
    cout<<cnt;
}