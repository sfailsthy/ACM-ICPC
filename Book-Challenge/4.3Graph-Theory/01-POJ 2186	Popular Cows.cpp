//created by sfailsthy 2016/12/14 19:42
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =10000+100;

int V;
vector<int> G[maxn];
vector<int> rG[maxn];//反向后的图的邻接表
vector<int> vs;//后序遍历顺序的顶点列表
bool used[maxn];//访问标记
int cmp[maxn];//所属的强连通分量的拓扑序

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]]){
            dfs(G[v][i]);
        }
    }
    vs.push_back(v);
}

void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i]]){
            rdfs(rG[v][i],k);
        }
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(!used[v]){
            dfs(v);
        }
    }

    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]){
            rdfs(vs[i],k++);
        }
    }
    return k;
}

int N,M;
int A[5*maxn],B[5*maxn];

void solve(){
    V=N;
    for(int i=0;i<M;i++){
        add_edge(A[i]-1,B[i]-1);
    }
    int n=scc();

    int u=0,num=0;
    for(int v=0;v<V;v++){
        if(cmp[v]==n-1){
            u=v;
            num++;
        }
    }

    memset(used,0,sizeof(used));
    rdfs(u,0);
    for(int v=0;v<V;v++){
        if(!used[v]){
            num=0;
            break;
        }
    }
    printf("%d\n",num);
}

int main(){
    while(scanf("%d%d",&N,&M)==2){
        for(int i=0;i<M;i++){
            scanf("%d%d",&A[i],&B[i]);
        }
        solve();
    }
    return 0;
}
