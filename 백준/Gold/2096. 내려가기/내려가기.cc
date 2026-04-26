#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> mx(3),mn(3);
    for(int i=0;i<3;i++)cin>>mx[i],mn[i]=mx[i];
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        vector<int> nmx(3),nmn(3);
        nmx[0]=max(mx[0],mx[1])+a; nmn[0]=min(mn[0],mn[1])+a;
        nmx[1]=max({mx[0],mx[1],mx[2]})+b; nmn[1]=min({mn[0],mn[1],mn[2]})+b;
        nmx[2]=max(mx[1],mx[2])+c; nmn[2]=min(mn[1],mn[2])+c;
        mx=nmx;mn=nmn;
    }
    cout<<*max_element(mx.begin(),mx.end())<<" "<<*min_element(mn.begin(),mn.end());
}