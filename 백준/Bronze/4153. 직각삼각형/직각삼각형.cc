#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c;
    while (cin >> a >> b >> c && (a||b||c)) {
        long long v[3] = {a,b,c};
        sort(v, v+3);
        cout << (v[0]*v[0]+v[1]*v[1]==v[2]*v[2] ? "right" : "wrong") << "\n";
    }
}