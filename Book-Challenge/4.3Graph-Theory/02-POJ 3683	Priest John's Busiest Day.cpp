//created by sfailsthy 2016/12/14 0:11
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =1000+10;

int V;
vector<int> G[2*maxn];
vector<int> rG[2*maxn];//反向后的图的邻接表
vector<int> vs;//后序遍历顺序的顶点列表
bool used[2*maxn];//访问标记
int cmp[2*maxn];//所属的强连通分量的拓扑序

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

int n;
int S[maxn],T[maxn],D[maxn];

void solve(){
    V=2*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(min(S[i]+D[i],S[j]+D[j])>max(S[i],S[j])){
                add_edge(i,n+j);
                add_edge(j,n+i);
            }

            if(min(S[i]+D[i],T[j])>max(S[i],T[j]-D[j])){
                add_edge(i,j);
                add_edge(j+n,i+n);
            }

            if(min(T[i],S[j]+D[j])>max(T[i]-D[i],S[j])){
                add_edge(i+n,j+n);
                add_edge(j,i);
            }

            if(min(T[i],T[j])>max(T[i]-D[i],T[j]-D[j])){
                add_edge(i+n,j);
                add_edge(j+n,i);
            }
        }
    }

    scc();

    for(int i=0;i<n;i++){
        if(cmp[i]==cmp[i+n]){
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
    for(int i=0;i<n;i++){
        if(cmp[i]>cmp[i+n]){
            printf("%02d:%02d %02d:%02d\n", S[i]/60,S[i]%60,(S[i]+D[i])/60,(S[i]+D[i])%60);
        }
        else{
            printf("%02d:%02d %02d:%02d\n", (T[i]-D[i])/60,(T[i]-D[i])%60,T[i]/60,T[i]%60);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%02d:%02d%02d:%02d%d",&a,&b,&c,&d,&D[i]);
        S[i]=60*a+b;
        T[i]=60*c+d;
    }
    solve();
    return 0;
}
