#include<bits/stdc++.h>
using namespace std;
int h,w;
char g[102][102];
bool keys[26],vis[102][102];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
vector<pair<int,int>> blocked[26];

void tryAdd(int x,int y,queue<pair<int,int>>&q){
    if(x<0||x>=h||y<0||y>=w||vis[x][y])return;
    char c=g[x][y];
    if(c=='*')return;
    if(isupper(c)&&!keys[c-'A']){blocked[c-'A'].push_back({x,y});return;}
    vis[x][y]=true;q.push({x,y});
}

int solve(){
    queue<pair<int,int>>q;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)
        if((i==0||i==h-1||j==0||j==w-1))tryAdd(i,j,q);
    int ans=0;
    while(!q.empty()){
        auto[x,y]=q.front();q.pop();
        if(g[x][y]=='$')ans++;
        if(islower(g[x][y])){
            int k=g[x][y]-'a';
            if(!keys[k]){keys[k]=true;for(auto[bx,by]:blocked[k])tryAdd(bx,by,q);blocked[k].clear();}
        }
        for(int d=0;d<4;d++)tryAdd(x+dx[d],y+dy[d],q);
    }
    return ans;
}

int main(){
    int T;cin>>T;
    while(T--){
        cin>>h>>w;
        memset(keys,0,sizeof(keys));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<26;i++)blocked[i].clear();
        for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>g[i][j];
        string s;cin>>s;
        if(s!="0")for(char c:s)keys[c-'a']=true;
        cout<<solve()<<"\n";
    }
}