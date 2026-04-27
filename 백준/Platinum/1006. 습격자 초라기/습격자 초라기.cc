#include<bits/stdc++.h>
using namespace std;
int N,W,cost[2][10004],a[10004],b[10004],c[10004];

void expand(){
    if(cost[0][0]+cost[1][0]<=W)a[0]=b[0]=c[0]=1;
    else a[0]=2,b[0]=c[0]=1;
    for(int i=1;i<N;i++){
        a[i]=a[i-1]+2;
        b[i]=c[i]=a[i-1]+1;
        if(cost[0][i]+cost[0][i-1]<=W)b[i]=min(b[i],c[i-1]+1);
        if(cost[1][i]+cost[1][i-1]<=W)c[i]=min(c[i],b[i-1]+1);
        a[i]=min({a[i],b[i]+1,c[i]+1});
        if(cost[0][i]+cost[1][i]<=W)a[i]=min(a[i],a[i-1]+1);
        if(cost[0][i]+cost[0][i-1]<=W&&cost[1][i]+cost[1][i-1]<=W)
            a[i]=min(a[i],(i>=2?a[i-2]:0)+2);
    }
}

void solve(){
    cin>>N>>W;
    for(int i=0;i<2;i++)for(int j=0;j<N;j++)cin>>cost[i][j];
    expand();
    int ans=a[N-1];
    if(N>1){
        if(cost[1][0]+cost[1][N-1]<=W){
            int t1=cost[1][0],t2=cost[1][N-1];
            cost[1][0]=cost[1][N-1]=W;expand();
            ans=min(ans,b[N-1]);
            cost[1][0]=t1;cost[1][N-1]=t2;
        }
        if(cost[0][0]+cost[0][N-1]<=W){
            int t1=cost[0][0],t2=cost[0][N-1];
            cost[0][0]=cost[0][N-1]=W;expand();
            ans=min(ans,c[N-1]);
            cost[0][0]=t1;cost[0][N-1]=t2;
        }
        if(cost[0][0]+cost[0][N-1]<=W&&cost[1][0]+cost[1][N-1]<=W){
            int t1=cost[0][0],t2=cost[0][N-1],t3=cost[1][0],t4=cost[1][N-1];
            cost[0][0]=cost[0][N-1]=cost[1][0]=cost[1][N-1]=W;expand();
            ans=min(ans,a[N-2]);
            cost[0][0]=t1;cost[0][N-1]=t2;cost[1][0]=t3;cost[1][N-1]=t4;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    int tc;cin>>tc;while(tc--)solve();
}