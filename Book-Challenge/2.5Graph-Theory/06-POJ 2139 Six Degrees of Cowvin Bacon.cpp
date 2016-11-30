//created by sfailsthy 2016/11/27 21:44
//n次Dijkstra算法，时间复杂度是O(VElogV)
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =300+10;
typedef pair<int,int> P;

int V,M;
int d[maxn];
struct edge{
    int to,d;
};
vector<edge> G[maxn];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
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
    scanf("%d%d",&V,&M);
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        int tmp[maxn];
        for(int i=0;i<n;i++){
            cin>>tmp[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n&&j!=i;j++){
                G[tmp[i]-1].push_back((edge){tmp[j]-1,1});
                G[tmp[j]-1].push_back((edge){tmp[i]-1,1});
            }
        }
    }

    int res=INF;
    for(int i=0;i<V;i++){
        dijkstra(i);
        int tmp=0;
        for(int j=0;j<V;j++){
            tmp+=d[j];
        }
        res=min(res,tmp);
    }
    double average=res*1.0/(V-1);
    printf("%d\n",(int)(100.0*average));
    return 0;
}
