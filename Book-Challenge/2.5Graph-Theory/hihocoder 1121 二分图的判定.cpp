//created by sfailsthy 2016/11/27 11:56
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn =1e4+10;
int n,m;
vector<int> G[maxn];
int color[maxn];

bool dfs(int u,int c){
    color[u]=c;
    
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(color[v]==0&&!dfs(v,-c)) return false;
        if(color[v]==c) return false;
    }
    return true;
}

void solve(){
    for(int i=0;i<n;i++){
        if(color[i]==0){
           if(!dfs(i,1)){
               printf("Wrong\n");
               return;
           } 
        }
    }
    
    printf("Correct\n");
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            u--;
            v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        memset(color,0,sizeof(color));
        solve();
    }
    return 0;
}
