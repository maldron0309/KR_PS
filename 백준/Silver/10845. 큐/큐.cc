#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    queue<int> q;
    while (N--) {
        string cmd; cin >> cmd;
        if (cmd == "push") { int x; cin >> x; q.push(x); }
        else if (cmd == "pop") { cout << (q.empty() ? -1 : (int)q.front()) << "\n"; if (!q.empty()) q.pop(); }
        else if (cmd == "size") cout << q.size() << "\n";
        else if (cmd == "empty") cout << q.empty() << "\n";
        else if (cmd == "front") cout << (q.empty() ? -1 : (int)q.front()) << "\n";
        else cout << (q.empty() ? -1 : (int)q.back()) << "\n";
    }
}