#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    cout << (int)round(tgamma(N+1)/tgamma(K+1)/tgamma(N-K+1));
}