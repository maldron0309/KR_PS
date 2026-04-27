#include<bits/stdc++.h>
using namespace std;
int p[100001];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
    int g,pp;cin>>g>>pp;
    iota(p,p+g+1,0);
    int ans=0;
    for(int i=0;i<pp;i++){
        int x;cin>>x;
        int f=find(x);
        if(f==0)break;
        ans++;p[f]=f-1;
    }
    cout<<ans;
}