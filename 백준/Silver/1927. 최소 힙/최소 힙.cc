#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin>>N;
    priority_queue<int,vector<int>,greater<int>> pq;
    while (N--) {
        int x; cin>>x;
        if (x==0) { cout<<(pq.empty()?0:pq.top())<<"\n"; if (!pq.empty()) pq.pop(); }
        else pq.push(x);
    }
}