//created by sfailsthy 2016/12/19 1:33
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn =1e5+10;
const int INF=1e9;

struct Edge{
    int from,to,color;
    Edge(int from=0,int to=0,int color=0):from(from),to(to),color(color){}
};

vector<Edge> edges;
vector<int> G[maxn];//存以i为开头的边的编号

void addEdge(int from,int to,int color){
    edges.push_back(Edge(from,to,color));
    int idx=edges.size()-1;
    G[from].push_back(idx);
}

int n,m;
int d[maxn];
int vis[maxn];

//从终点逆向BFS，求出每个点到终点的最短距离
void rev_bfs(){
    memset(vis,0,sizeof(vis));
    queue<int> que;
    vis[n-1]=1;
    d[n-1]=0;
    que.push(n-1);

    while(!que.empty()){
        int v=que.front();
        que.pop();

        for(int i=0;i<G[v].size();i++){
            int e=G[v][i];
            int u=edges[e].to;
            if(!vis[u]){
                vis[u]=1;
                d[u]=d[v]+1;
                que.push(u);
            }
        }
    }
}


void bfs(){
    vector<int> ans;
    memset(vis,0,sizeof(vis));
    vis[0]=1;

    vector<int> next;
    next.push_back(0);

    for(int i=0;i<d[0];i++){
        int min_color=INF;
        for(int j=0;j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                int e=G[u][k];
                int v=edges[e].to;
                if(d[u]==d[v]+1){
                    min_color=min(min_color,edges[e].color);
                }
            }
        }
        ans.push_back(min_color);

        vector<int> next2;
        for(int j=0;j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                int e=G[u][k];
                int v=edges[e].to;
                if(d[u]==d[v]+1&&!vis[v]&&min_color==edges[e].color){
                    vis[v]=1;
                    next2.push_back(v);
                }
            }
        }
        next=next2;
    }

    printf("%d\n",ans.size());
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        edges.clear();
        for(int i=0;i<n;i++){
            G[i].clear();
        }

        for(int i=0;i<m;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addEdge(u-1,v-1,c);
            addEdge(v-1,u-1,c);
        }
        rev_bfs();
        bfs();
    }
    return 0;
}
