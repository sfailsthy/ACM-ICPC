//created by sfailsthy 2016/12/9 1:27
//最大团是其补图的最大独立集
//md，忘记最后三个0输入结束，少加了个&&G，直接WA。。。竟然一直在找其他原因。。
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

void init(){
    for(int i=0;i<V;i++){
        G[i].clear();
    }
}

int main(){
    int G,B,M,kase=0;
    bool graph[maxn][maxn];
    while(scanf("%d%d%d",&G,&B,&M)==3&&G){
        V=G+B;
        init();
        memset(graph,0,sizeof(graph));

        for(int i=0;i<M;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            graph[x][y]=true;
        }

        for(int i=0;i<G;i++){
            for(int j=0;j<B;j++){
                if(!graph[i][j]){
                    add_edge(i,j+G);
                }
            }
        }
        printf("Case %d: %d\n",++kase,V-bitpartite_matching());
    }
    return 0;
}
