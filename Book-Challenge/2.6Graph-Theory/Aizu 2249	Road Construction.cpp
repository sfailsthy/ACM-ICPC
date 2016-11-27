//created by sfailsthy 2016/11/27 16:13
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int maxn =10000+10;
#define INF 0x7fffffff

struct edge{
    int to,d,cost;
};
typedef pair<int,int> P;

int N,M;
vector<edge> G[maxn];
int d[maxn];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+N,INF);
    d[s]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top();
        que.pop();

        int v=p.second;
        if(d[v]<p.first) continue;

        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.d){
                d[e.to]=d[v]+e.d;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(cin>>N>>M&&N){
        for(int i=0;i<N;i++){
            G[i].clear();
        }

        for(int i=0;i<M;i++){
            int u,v,x,cost;
            cin>>u>>v>>x>>cost;
            u--;
            v--;
            G[u].push_back((edge){v,x,cost});
            G[v].push_back((edge){u,x,cost});
        }

        dijkstra(0);

        int res=0;
        for(int i=1;i<N;i++){
            int tmp=INF;
            for(int j=0;j<G[i].size();j++){
                if(d[G[i][j].to]+G[i][j].d==d[i]){
                    tmp=min(tmp,G[i][j].cost);
                }
            }
            res+=tmp;
        }
        cout<<res<<endl;
    }
    return 0;
}
