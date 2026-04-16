#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<pair<int,int>> v(N);
    for (auto& [x,y] : v) cin >> x >> y;
    for (int i = 0; i < N; i++) {
        int rank = 1;
        for (int j = 0; j < N; j++)
            if (v[j].first > v[i].first && v[j].second > v[i].second) rank++;
        cout << rank << " \n"[i==N-1];
    }
}