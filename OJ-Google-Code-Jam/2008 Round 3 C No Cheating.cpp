//解题报告:http://blog.csdn.net/qq_33929112/article/details/52655302
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
  
#define MAX_N 85  
#define MAX_M 85  
  
//二分图匹配模板  
#define MAX_V 6405  
  
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
  
const int dx[]={-1,-1,1,1};  
const int dy[]={-1,0,-1,0};  
  
int M,N;  
char seat[MAX_M][MAX_N];  
  
void solve()  
{  
    int num=0;  
    V=M*N;  
    for(int v=0;v<V;v++){  
        G[v].clear();  
    }  
    for(int y=0;y<M;y++){  
        for(int x=0;x<N;x++){  
            if(seat[y][x]=='.'){  
                num++;  
                for(int k=0;k<4;k++){  
                    int y2=y+dy[k];  
                    int x2=x+dx[k];  
                    if(0<=x2&&x2<N&&0<=y2&&y2<M&&seat[y2][x2]=='.'){  
                        add_edge(x*M+y,x2*M+y2);  
                    }  
                }  
            }  
        }  
    }  
    printf("%d\n",num-bipartite_matching());  
}  
int main()  
{  
    freopen("C-large-practice.in","r",stdin);  
    freopen("C-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d%d",&M,&N);  
        for(int i=0;i<M;i++){  
            for(int j=0;j<N;j++){  
                cin>>seat[i][j];  
            }  
        }  
        printf("Case #%d: ",++kase);  
        solve();  
    }  
    return 0;  
}  
