//解题报告:http://blog.csdn.net/qq_33929112/article/details/52685683
#include <algorithm>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <map>  
#include <queue>  
#include <string>  
#include <set>  
#include <vector>  
using namespace std;  
  
#define maxk 30  
#define maxn 105  
#define MAX_V 205  
  
int N,K;  
int P[maxn][maxk];  
  
//二分图匹配模板  
  
  
int V;//顶点数  
vector<int> G[MAX_V];//图的邻接表表示  
int match[MAX_V];//所匹配的顶点  
bool used[MAX_V];//DFS中用到的访问标记  
  
//向图中增加一条连接u和v的边  
void add_edge(int u,int v)  
{  
    G[u].push_back(v);  
    G[v].push_back(u);  
}  
  
//通过DFS寻找增广路  
bool dfs(int v)  
{  
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
int bipartite_matching()  
{  
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
//二分图匹配模板  
  
void solve()  
{  
    V=N*2;  
    for(int i=0;i<V;i++){  
        G[i].clear();  
    }  
  
    for(int i=0;i<N;i++){  
        for(int j=0;j<N;j++){  
            if(i==j) continue;  
            bool ok=true;  
            for(int k=0;k<K;k++){  
                if(P[j][k]>=P[i][k]){  
                    ok=false;  
                }  
            }  
            if(ok){  
                add_edge(i,N+j);  
            }  
        }  
    }  
    int ans=N-bipartite_matching();  
    printf("%d\n",ans);  
}  
int main()  
{  
    freopen("C-large-practice.in","r",stdin);  
    freopen("C-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d%d",&N,&K);  
        for(int i=0;i<N;i++){  
            for(int k=0;k<K;k++){  
                scanf("%d",&P[i][k]);  
            }  
        }  
        printf("Case #%d: ",++kase);  
        solve();  
    }  
    return 0;  
}  
