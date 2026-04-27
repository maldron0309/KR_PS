#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{ll x,y;};
ll cross(P o,P a,P b){return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);}
bool onSeg(P p,P a,P b){return min(a.x,b.x)<=p.x&&p.x<=max(a.x,b.x)&&min(a.y,b.y)<=p.y&&p.y<=max(a.y,b.y);}
int main(){
    P a,b,c,d;cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    ll d1=cross(c,d,a),d2=cross(c,d,b),d3=cross(a,b,c),d4=cross(a,b,d);
    if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0))){cout<<1;return 0;}
    if(!d1&&onSeg(a,c,d)){cout<<1;return 0;}
    if(!d2&&onSeg(b,c,d)){cout<<1;return 0;}
    if(!d3&&onSeg(c,a,b)){cout<<1;return 0;}
    if(!d4&&onSeg(d,a,b)){cout<<1;return 0;}
    cout<<0;
}