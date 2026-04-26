#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Mat;
int N;
Mat mul(Mat&a,Mat&b){
    Mat c(N,vector<ll>(N,0));
    for(int i=0;i<N;i++)for(int k=0;k<N;k++)for(int j=0;j<N;j++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%1000;
    return c;
}
Mat mpow(Mat a,ll b){
    Mat r(N,vector<ll>(N,0));for(int i=0;i<N;i++)r[i][i]=1;
    for(;b;b>>=1){if(b&1)r=mul(r,a);a=mul(a,a);}return r;
}
int main(){
    ll b;cin>>N>>b;
    Mat a(N,vector<ll>(N));
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
    auto r=mpow(a,b);
    for(int i=0;i<N;i++){for(int j=0;j<N;j++)cout<<r[i][j]<<" ";cout<<"\n";}
}