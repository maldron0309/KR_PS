#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vector<long long>a(n),b(n),c(n),d(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
    vector<long long>ab,cd;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){ab.push_back(a[i]+b[j]);cd.push_back(c[i]+d[j]);}
    sort(ab.begin(),ab.end());sort(cd.begin(),cd.end());
    long long ans=0;
    int l=0,r=cd.size()-1;
    while(l<(int)ab.size()&&r>=0){
        long long s=ab[l]+cd[r];
        if(s==0){
            long long cl=ab[l],cr=cd[r];
            long long lc=0,rc=0;
            while(l<(int)ab.size()&&ab[l]==cl){lc++;l++;}
            while(r>=0&&cd[r]==cr){rc++;r--;}
            ans+=lc*rc;
        }else if(s<0)l++;else r--;
    }
    cout<<ans;
}