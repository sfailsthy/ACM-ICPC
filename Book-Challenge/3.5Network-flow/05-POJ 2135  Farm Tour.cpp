//created by sfailsthy 2016/12/8 22:52
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn =1000+10;
#define INF 0x3f3f3f3f

//终点，容量，费用，反向边
struct edge{
    int to,cap,cost,rev;
};

int V;
vector<edge> G[maxn];
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路中的前驱结点和对应的边

//向图中增加一条从from到to的容量为cap费用为cost的边
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

//求解从s到t的流量为f的最小费用流
//如果不能再增广返回-1
int min_cost_flow(int s,int t,int f){
    int res=0;
    while(f>0){
        //利用Bellman-Ford算法求s到t的最短路
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update=true;
        while(update){
            update=false;
            for(int v=0;v<V;v++){
                if(dist[v]==INF) continue;
                for(int i=0;i<G[v].size();i++){
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost){
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }

        //不能再增广
        if(dist[t]==INF){
            return -1;
        }

        //沿s到t的最短路尽量增广
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}

int N,M;
int a[10*maxn],b[10*maxn],c[10*maxn];

void solve(){
    it s=0,t=N-1;
    V=N;
    for(int i=0;i<M;i++){
        add_edge(a[i]-1,b[i]-1,1,c[i]);
        add_edge(b[i]-1,a[i]-1,1,c[i]);
    }

    printf("%d\n",min_cost_flow(s,t,2));
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    solve();
    return 0;
}
