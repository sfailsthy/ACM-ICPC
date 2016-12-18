//created by sfailsthy 2016/12/18 13:35
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =100+10;

int n,m,t;
int c[maxn],topo[maxn];
int G[maxn][maxn];

bool dfs(int u){
    c[u]=-1;
    for(int v=0;v<n;v++){
        if(G[u][v]){
            if(c[v]<0) return false;
            else if(!c[v]&&!dfs(v)) return false;
        }
    }
    c[u]=1;
    topo[--t]=u;
    return true;
}

bool toposort(){
    t=n;
    memset(c,0,sizeof(c));
    for(int u=0;u<n;u++){
        if(!c[u]&&!dfs(u)){
            return false;
        }
    }
    return true;
}

int main(){
    while(scanf("%d%d",&n,&m)==2&&n){
        memset(G,0,sizeof(G));
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            G[u][v]=1;
        }
        bool flag=toposort();
        for(int i=0;i<n;i++){
            printf("%d%c",topo[i]+1,i+1==n?'\n':' ');
        }
    }
    return 0;
}
