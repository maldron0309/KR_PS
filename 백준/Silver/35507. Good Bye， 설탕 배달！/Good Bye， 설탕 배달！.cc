#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,4> a4;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<a4> v(N);
        for(auto& p:v) cin>>p[0]>>p[1]>>p[2]>>p[3];
        sort(v.begin(),v.end(),[](const a4&a,const a4&b){return a[3]<b[3];});
        bool ok=true;
        ll ma=0,mb=0,mc=0;
        for(int i=0;i<N;i++){
            ma=max(ma,v[i][0]);
            mb=max(mb,v[i][1]);
            mc=max(mc,v[i][2]);
            if(ma+mb+mc+i+1>v[i][3]){ok=false;break;}
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
}
