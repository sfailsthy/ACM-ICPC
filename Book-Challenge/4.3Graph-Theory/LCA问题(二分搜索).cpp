//created by sfailsthy 2016/12/17 21:05
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAX_V =10000+10;
const int MAX_LOG_V =100;

vector<int> G[MAX_V];
int root;
int V;
int parent[MAX_LOG_V][MAX_V];//向上走2^k步到达的结点
int depth[MAX_V];

void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i]!=p){
            dfs(G[v][i],v,d+1);
        }
    }
}

//预处理
void init(){
    //预处理出depth和parent[0]
    dfs(root,-1,0);
    //预处理parent
    for(int k=0;k+1<MAX_LOG_V;k++){
        for(int v=0;v<V;v++){
            if(parent[k][v]<0){
                parent[k+1][v]=-1;
            }
            else{
                parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
    }
}

//计算lca
int lca(int u,int v){
    if(depth[u]>depth[v]){
        swap(u,v);
    }

    for(int k=0;k<MAX_LOG_V;k++){
        if((depth[v]-depth[u])>>k&1){
            v=parent[k][v];
        }
    }

    if(u==v) return u;
    //利用二分搜索计算lca
    for(int k=MAX_LOG_V-1;k>=0;k--){
        if(parent[k][v]!=parent[k][u]){
            v=parent[k][v];
            u=parent[k][u];
        }
    }
    return parent[0][u];
}

int main(){
    while(scanf("%d",&V)!=EOF&&V){
        root=1;
        for(int u=1;u<=V;u++){
            int v;
            while(scanf("%d",&v)!=EOF&&v){
                G[u].push_back(v);
            }
        }
        init();

        int u,v;
        while(scanf("%d%d",&u,&v)!=EOF){
            printf("%d\n",lca(u,v));
        }
    }
    return 0;
}
