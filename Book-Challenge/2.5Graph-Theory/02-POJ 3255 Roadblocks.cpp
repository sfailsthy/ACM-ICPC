//created by sfailsthy 2016/11/27 20:17
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn =5000+10;
#define INF 0x3f3f3f3f
typedef pair<int,int> P;

int N,R;
struct edge{
    int to,cost;
};
vector<edge> G[maxn];

int dist[maxn];//最短路
int dist2[maxn];//次短路

void solve(){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(dist,dist+N,INF);
    fill(dist2,dist2+N,INF);
    dist[0]=0;
    que.push(P(0,0));

    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second,d=p.first;

        if(dist2[v]<d) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            int d2=d+e.cost;

            if(dist[e.to]>d2){
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }

            if(dist2[e.to]>d2&&dist[e.to]<d2){
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }

    printf("%d\n",dist2[N-1]);
}

int main(){
    scanf("%d%d",&N,&R);
    for(int i=0;i<R;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        u--;
        v--;
        G[u].push_back((edge){v,d});
        G[v].push_back((edge){u,d});
    }
    solve();
    return 0;
}
