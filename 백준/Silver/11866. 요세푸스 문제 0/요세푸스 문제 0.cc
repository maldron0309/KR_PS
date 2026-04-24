#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    list<int> L;
    for (int i = 1; i <= N; i++) L.push_back(i);
    auto it = L.begin();
    cout << "<";
    while (!L.empty()) {
        for (int i = 0; i < K-1; i++) { if (++it == L.end()) it = L.begin(); }
        cout << *it;
        it = L.erase(it);
        if (it == L.end()) it = L.begin();
        if (!L.empty()) cout << ", ";
    }
    cout << ">";
}