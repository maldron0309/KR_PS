#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N; cin >> N;
    long long s[6]; for (auto& x : s) cin >> x;
    long long T, P; cin >> T >> P;
    long long total = 0;
    for (int i = 0; i < 6; i++) total += (s[i] + T - 1) / T;
    cout << total << "\n";
    cout << N/P << " " << N%P << "\n";
}