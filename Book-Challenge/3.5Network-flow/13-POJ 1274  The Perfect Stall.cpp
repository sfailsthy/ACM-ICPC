//created by sfailsthy 2016/12/8 23:49
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn =400+10;
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
    int N,M;
    while(scanf("%d%d",&N,&M)==2){
        V=N+M;
        for(int i=0;i<V;i++){
            G[i].clear();
        }

        for(int i=0;i<N;i++){
            int x,u;
            scanf("%d",&x);
            for(int j=0;j<x;j++){
                scanf("%d",&u);
                add_edge(i,N+u-1);
            }
        }
        printf("%d\n",bitpartite_matching());
    }
    return 0;
}
