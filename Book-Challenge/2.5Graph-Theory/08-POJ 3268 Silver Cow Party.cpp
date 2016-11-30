//created by sfailsthy 2016/11/27 16:51
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int maxn =1000+10;
#define INF 0x7fffffff

struct edge{
    int to,d;
};
typedef pair<int,int> P;

int N,M;
vector<edge> G[maxn];
int d[maxn];
int t[maxn];

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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int X;
    while(cin>>N>>M>>X&&N){
        for(int i=0;i<N;i++){
            G[i].clear();
        }

        for(int i=0;i<M;i++){
            int u,v,x;
            cin>>u>>v>>x;
            u--;
            v--;
            G[u].push_back((edge){v,x});
        }

        dijkstra(X-1);

        for(int i=0;i<N;i++){
            t[i]=d[i];
        }

        for(int i=0;i<N;i++){
            if(i==X-1) continue;
            dijkstra(i);
            t[i]+=d[X-1];
        }
        int res=t[0];
        for(int i=0;i<N;i++){
            res=max(res,t[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
