#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i*i<=n;i++)if(sieve[i])for(int j=i*i;j<=n;j+=i)sieve[j]=false;
    vector<int>primes;
    for(int i=2;i<=n;i++)if(sieve[i])primes.push_back(i);
    int ans=0,l=0,r=0,sum=0;
    while(r<(int)primes.size()){
        sum+=primes[r++];
        while(sum>n)sum-=primes[l++];
        if(sum==n)ans++;
    }
    cout<<ans;
}