#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K; cin>>N>>K;
    vector<int> dist(100001,-1);
    queue<int> q; q.push(N); dist[N]=0;
    while (!q.empty()) {
        int x=q.front(); q.pop();
        if (x==K) { cout<<dist[x]; return 0; }
        for (int nx:{x-1,x+1,2*x}) if (nx>=0&&nx<=100000&&dist[nx]==-1) { dist[nx]=dist[x]+1; q.push(nx); }
    }
}