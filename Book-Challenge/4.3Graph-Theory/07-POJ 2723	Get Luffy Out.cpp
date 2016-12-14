//created by sfailsthy 2016/12/14 13:45
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =1000+100;

int V;
vector<int> G[4*maxn];
vector<int> rG[4*maxn];//反向后的图的邻接表
vector<int> vs;//后序遍历顺序的顶点列表
bool used[4*maxn];//访问标记
int cmp[4*maxn];//所属的强连通分量的拓扑序

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

int n,m;
int key[maxn][2];
int door[2*maxn][2];

bool check(int x){
    V=4*n;
    for(int i=0;i<V;i++){
        G[i].clear();
        rG[i].clear();
    }

    for(int i=0;i<n;i++){
        add_edge(key[i][0],key[i][1]+2*n);
        add_edge(key[i][1],key[i][0]+2*n);
    }

    for(int i=0;i<x;i++){
        add_edge(door[i][0]+2*n,door[i][1]);
        add_edge(door[i][1]+2*n,door[i][0]);
    }

    scc();

    for(int i=0;i<2*n;i++){
        if(cmp[i]==cmp[i+2*n]){
            return false;
        }
    }
    return true;
}

void solve(){
    int lb=0,ub=m+1;
    while(ub>lb){
        int mid=(ub+lb)>>1;
        if(check(mid)){
            lb=mid+1;
        }
        else{
            ub=mid;
        }
    }
    printf("%d\n",lb-1);
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++){
            scanf("%d%d",&key[i][0],&key[i][1]);
        }

        for(int i=0;i<m;i++){
            scanf("%d%d",&door[i][0],&door[i][1]);
        }
        solve();
    }
    return 0;
}
