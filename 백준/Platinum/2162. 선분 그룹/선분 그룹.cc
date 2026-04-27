#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[3001],sz[3001];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void unite(int a,int b){a=find(a);b=find(b);if(a==b)return;if(sz[a]<sz[b])swap(a,b);p[b]=a;sz[a]+=sz[b];}
struct P{ll x,y;};
ll cross(P o,P a,P b){return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);}
bool onSeg(P p,P a,P b){return min(a.x,b.x)<=p.x&&p.x<=max(a.x,b.x)&&min(a.y,b.y)<=p.y&&p.y<=max(a.y,b.y);}
bool intersect(P a,P b,P c,P d){
    ll d1=cross(c,d,a),d2=cross(c,d,b),d3=cross(a,b,c),d4=cross(a,b,d);
    if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))return true;
    if(!d1&&onSeg(a,c,d))return true;
    if(!d2&&onSeg(b,c,d))return true;
    if(!d3&&onSeg(c,a,b))return true;
    if(!d4&&onSeg(d,a,b))return true;
    return false;
}
int main(){
    int n;cin>>n;
    vector<array<ll,4>>seg(n);
    for(auto&s:seg)cin>>s[0]>>s[1]>>s[2]>>s[3];
    iota(p,p+n,0);fill(sz,sz+n,1);
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        P a={seg[i][0],seg[i][1]},b={seg[i][2],seg[i][3]};
        P c={seg[j][0],seg[j][1]},d={seg[j][2],seg[j][3]};
        if(intersect(a,b,c,d))unite(i,j);
    }
    map<int,int>cnt;
    for(int i=0;i<n;i++)cnt[find(i)]++;
    cout<<cnt.size()<<"\n"<<max_element(cnt.begin(),cnt.end(),[](auto&a,auto&b){return a.second<b.second;})->second;
}