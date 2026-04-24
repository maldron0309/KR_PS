#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin>>s;
    vector<string> parts;
    stringstream ss(s);
    string tok;
    while (getline(ss,tok,'-')) parts.push_back(tok);
    int result=0;
    for (int i=0;i<(int)parts.size();i++) {
        int sum=0;
        stringstream ss2(parts[i]);
        string num;
        while (getline(ss2,num,'+')) sum+=stoi(num);
        result += (i==0)?sum:-sum;
    }
    cout<<result;
}