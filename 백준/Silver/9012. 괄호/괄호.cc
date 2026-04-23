#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int cnt = 0; bool ok = true;
        for (char c : s) {
            if (c == '(') cnt++;
            else { if (--cnt < 0) { ok = false; break; } }
        }
        cout << (ok && cnt == 0 ? "YES" : "NO") << "\n";
    }
}