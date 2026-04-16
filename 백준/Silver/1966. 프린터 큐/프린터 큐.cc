#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        queue<pair<int,int>> q;
        for (int i = 0; i < N; i++) {
            int p; cin >> p;
            q.push({p, i});
        }
        int cnt = 0;
        while (true) {
            auto [pri, idx] = q.front(); q.pop();
            bool hasHigher = false;
            for (auto tmp = q; !tmp.empty(); tmp.pop())
                if (tmp.front().first > pri) { hasHigher = true; break; }
            if (hasHigher) q.push({pri, idx});
            else {
                cnt++;
                if (idx == M) { cout << cnt << "\n"; break; }
            }
        }
    }
}