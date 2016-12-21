//created by sfailsthy 2016/12/21 13:05
/**************************************************************
    Problem: 1059
    User: sfailsthy
    Language: C++
    Result: Accepted
    Time:348 ms
    Memory:1696 kb
****************************************************************/
//BZOJ自动生成这个，很人性化。。。
 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
const int maxn =400+10;
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
            match[v]=u;
            match[u]=v;
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
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        V=2*n;
        for(int i=0;i<V;i++){
            G[i].clear();
        }
 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                scanf("%d",&x);
                if(x){
                    add_edge(i,j+n);
                }
            }
        }
 
        int res=bitpartite_matching();
        if(res==n){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
