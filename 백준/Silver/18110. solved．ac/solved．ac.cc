#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n == 0) { cout << 0; return 0; }
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    int ex = (int)round(n * 0.15);
    double sum = 0;
    int cnt = n - 2*ex;
    for (int i = ex; i < n-ex; i++) sum += v[i];
    cout << (int)round(sum/cnt);
}