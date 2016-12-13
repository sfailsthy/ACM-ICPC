//created by sfailsthy 2016/12/13 23:07
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =1000+10;

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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    V=2*n;
    int a,b,c;
    char op[4];
    for(int i=0;i<m;i++){
        scanf("%d%d%d%s",&a,&b,&c,op);
        if(c==1){
            if(op[0]=='A'){
                //!a-a,!b-b
                add_edge(a+n,a);
                add_edge(b+n,b);
            }

            else if(op[0]=='O'){
                //!a-b,!b-a
                add_edge(a+n,b);
                add_edge(b+n,a);
            }

            else{
                //a-!b,!a-b,b-!a,!b-a
                add_edge(a,b+n);
                add_edge(a+n,b);
                add_edge(b,a+n);
                add_edge(b+n,a);
            }
        }

        else{
            if(op[0]=='A'){
                //a-!b,b-!a
                add_edge(a,b+n);
                add_edge(b,a+n);
            }

            else if(op[0]=='O'){
                //a-!a,b-!b
                add_edge(a,a+n);
                add_edge(b,b+n);
            }

            else{
                //a-b,!a-!b,b-a,!b-!a
                add_edge(a,b);
                add_edge(a+n,b+n);
                add_edge(b,a);
                add_edge(b+n,a+n);
            }
        }
    }

    scc();

    for(int i=0;i<n;i++){
        if(cmp[i]==cmp[i+n]){
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
