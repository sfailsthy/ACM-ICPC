//created by sfailsthy 2016/12/21 0:32
//使用Dijkstra算法好快，0ms。。。
//这题与挑战上poj那道例题，多一个条件是不能走重复的点，即点上的容量有限制，使用拆点法
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int maxn =2000+10;
#define INF 0x3f3f3f3f
typedef pair<int,int> P;

struct edge{
   int to,cap,cost,rev; 
};

int V,E;
vector<edge> G[maxn];
int h[maxn];//势
int dist[maxn];//最短距离
int prevv[maxn],preve[maxn];//最短路中的前驱结点和对应的边

void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

//求解最小费用流
int min_cost_flow(int s,int t,int f){
    int res=0;
    fill(h,h+V,0);
    while(f>0){
        //使用Dijkstra算法更新h
        priority_queue<P,vector<P>,greater<P> > que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));

        while(!que.empty()){
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;

            for(int i=0;i<G[v].size();i++){
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }

        if(dist[t]==INF){
            //不能再增广
            return -1;
        }

        for(int v=0;v<V;v++){
            h[v]+=dist[v];
        }

        //沿s到t的最短路尽量增广
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];

        for(int v=t;v!=s;v=prevv[v]){
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}

int main(){
    int n;
    while(scanf("%d%d",&n,&E)==2&&n){
        V=2*n-2;
        for(int i=0;i<V;i++){
            G[i].clear();
        }

        for(int i=0;i<E;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a!=1&&a!=n) a+=n-2;
            else a--;
            b--;
            add_edge(a,b,1,c);
        }

        for(int i=1;i<n-1;i++){
            add_edge(i,i+n-1,1,0);
        }

        printf("%d\n",min_cost_flow(0,n-1,2));
    }
    return 0;
}
