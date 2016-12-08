//created by sfailsthy 2016/12/8 22:32
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxv =1000+10;
const int maxk =10000+10;

int V;
vector<int> G[maxv];
int match[maxv];//所匹配的顶点
bool used[maxv];//DFS中用到的访问标记

//向图中增加一条连接u和v的边
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

//通过DFS寻找增广路
bool dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

//求解二分图的最大匹配
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

int N,K;
int R[maxk],C[maxk];

void solve(){
    V=2*N;
    for(int i=0;i<K;i++){
        add_edge(R[i]-1,N+C[i]-1);
    }
    printf("%d\n",bitpartite_matching());
}

int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++){
        scanf("%d%d",&R[i],&C[i]);
    }
    solve();
    return 0;
}
