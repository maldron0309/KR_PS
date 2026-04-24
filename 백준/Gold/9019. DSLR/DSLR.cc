#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T;
    while(T--) {
        int A,B; cin>>A>>B;
        vector<int> dist(10000,-1);
        vector<string> path(10000);
        queue<int> q; q.push(A); dist[A]=0; path[A]="";
        while(!q.empty()) {
            int n=q.front(); q.pop();
            auto go=[&](int nx, char c) {
                if(dist[nx]==-1) { dist[nx]=dist[n]+1; path[nx]=path[n]+c; q.push(nx); }
            };
            go((2*n)%10000,'D');
            go(n==0?9999:n-1,'S');
            go((n%1000)*10+n/1000,'L');
            go((n%10)*1000+n/10,'R');
        }
        cout<<path[B]<<"\n";
    }
}