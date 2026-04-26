#include<bits/stdc++.h>
using namespace std;
int l[27],r2[27];
void pre(int n){if(n<0)return;cout<<(char)('A'+n);pre(l[n]);pre(r2[n]);}
void in(int n){if(n<0)return;in(l[n]);cout<<(char)('A'+n);in(r2[n]);}
void post(int n){if(n<0)return;post(l[n]);post(r2[n]);cout<<(char)('A'+n);}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char a,b,c;cin>>a>>b>>c;
        l[a-'A']=b=='.'?-1:b-'A';
        r2[a-'A']=c=='.'?-1:c-'A';
    }
    pre(0);cout<<"\n";in(0);cout<<"\n";post(0);cout<<"\n";
}