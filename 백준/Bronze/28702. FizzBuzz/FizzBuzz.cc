#include <bits/stdc++.h>
using namespace std;
string fizz(long long i) {
    if (i%15==0) return "FizzBuzz";
    if (i%3==0) return "Fizz";
    if (i%5==0) return "Buzz";
    return to_string(i);
}
long long getI(string s) {
    if (s == "Fizz" || s == "Buzz" || s == "FizzBuzz") return -1;
    return stoll(s);
}
int main() {
    string a, b, c; cin >> a >> b >> c;
    long long i = -1;
    if (getI(c) != -1) i = getI(c) - 2;
    else if (getI(b) != -1) i = getI(b) - 1;
    else i = getI(a);
    cout << fizz(i + 3);
}