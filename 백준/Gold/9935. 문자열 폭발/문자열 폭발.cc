#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,b;cin>>s>>b;
    int m=b.size();
    vector<char> st;
    vector<int> idx;
    for(char c:s){
        st.push_back(c);
        idx.push_back(st.size()>=m&&string(st.end()-m,st.end())==b?1:0);
        if(idx.back()){for(int i=0;i<m;i++){st.pop_back();idx.pop_back();}}
    }
    if(st.empty())cout<<"FRULA";
    else for(char c:st)cout<<c;
}