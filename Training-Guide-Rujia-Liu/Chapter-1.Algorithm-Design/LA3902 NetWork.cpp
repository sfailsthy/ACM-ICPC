//题目链接:https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1903
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
#include<cmath>  
#include<bitset>  
#include<sstream>  
#include<stack>  
using namespace std;  
#define INF 0x7fffffff  
typedef long long ll;  
typedef pair<int,int> P;  
const int maxn=1000+10;  
int n,s,k;  
vector<int> gr[maxn],nodes[maxn];  
int fa[maxn];  
bool coverd[maxn];  
  
void dfs(int u,int f,int d)  
{  
    fa[u]=f;  
    int nc=gr[u].size();  
    //nc==1表示u是叶子结点  
    if(nc==1&&d>k) nodes[d].push_back(u);  
    for(int i=0;i<nc;i++){  
        int v=gr[u][i];  
        if(v!=f) dfs(v,u,d+1);  
    }  
}  
  
void dfs2(int u,int f,int d)  
{  
    coverd[u]=true;  
    int nc=gr[u].size();  
    for(int i=0;i<nc;i++){  
        int v=gr[u][i];  
        if(v!=f&&d<k) dfs2(v,u,d+1);//只覆盖到新服务器距离不超过k的结点  
    }  
}  
  
void solve()  
{  
    int ans=0;  
    memset(coverd,0,sizeof(coverd));  
    for(int d=n-1;d>k;d--){  
        for(int i=0;i<nodes[d].size();i++){  
            int u=nodes[d][i];  
            if(coverd[u]) continue;//不考虑已覆盖的结点  
  
            int v=u;  
            for(int j=0;j<k;j++) v=fa[v];//v是u的k级祖先  
            dfs2(v,-1,0);//在结点v出放服务器  
            ans++;  
        }  
    }  
    printf("%d\n",ans);  
}  
  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d%d%d",&n,&s,&k);  
        for(int i=1;i<=n;i++){  
            gr[i].clear();  
            nodes[i].clear();  
        }  
        for(int i=0;i<n-1;i++){  
            int a,b;  
            scanf("%d%d",&a,&b);  
            gr[a].push_back(b);  
            gr[b].push_back(a);  
        }  
        dfs(s,-1,0);  
        solve();  
    }  
    return 0;  
}  
