#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T;
    while(T--) {
        string p; cin>>p;
        int n; cin>>n;
        string arr; cin>>arr;
        deque<string> dq;
        string tmp=""; for(char c:arr) { if(c==','||c=='['||c==']') { if(!tmp.empty()) { dq.push_back(tmp); tmp=""; } } else tmp+=c; }
        bool rev=false, err=false;
        for(char c:p) {
            if(c=='R') rev=!rev;
            else { if(dq.empty()) { err=true; break; } if(rev) dq.pop_back(); else dq.pop_front(); }
        }
        if(err) { cout<<"error\n"; continue; }
        cout<<"[";
        for(int i=0;i<(int)dq.size();i++) { if(i) cout<<","; cout<<(rev?dq[dq.size()-1-i]:dq[i]); }
        cout<<"]\n";
    }
}