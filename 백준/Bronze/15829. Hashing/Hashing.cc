#include <bits/stdc++.h>
using namespace std;
int main() {
    int L; cin >> L;
    string s; cin >> s;
    long long H = 0, r = 31, M = 1234567891, pw = 1;
    for (int i = 0; i < L; i++) {
        H = (H + (s[i]-'a'+1) * pw) % M;
        pw = pw * r % M;
    }
    cout << H;
}