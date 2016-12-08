//created by sfailsthy 2016/12/8 23:21
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn =500+10;
#define INF 0x3f3f3f3f

int V;
vector<int> G[maxn];
int match[maxn];
bool used[maxn];

void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}

int bitpartite_matching(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++){
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    while(scanf("%d",&V)!=EOF){
        for(int i=0;i<V;i++){
            G[i].clear();
        }

        for(int i=0;i<V;i++){
            int v,m,u;
            scanf("%d: (%d)",&v,&m);
            for(int i=0;i<m;i++){
                scanf("%d",&u);
                G[v].push_back(u);
            }
        }
        printf("%d\n",V-bitpartite_matching());
    }
    return 0;
}
