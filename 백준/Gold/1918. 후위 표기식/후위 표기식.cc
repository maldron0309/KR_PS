#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    stack<char>st;
    string res;
    auto prec=[](char c){return c=='*'||c=='/'?2:1;};
    for(char c:s){
        if(isalpha(c))res+=c;
        else if(c=='(')st.push(c);
        else if(c==')'){while(st.top()!='('){res+=st.top();st.pop();}st.pop();}
        else{while(!st.empty()&&st.top()!='('&&prec(st.top())>=prec(c)){res+=st.top();st.pop();}st.push(c);}
    }
    while(!st.empty()){res+=st.top();st.pop();}
    cout<<res;
}