//created by sfailsthy 2016/12/21 1:48
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn =100+10;
#define INF 0x3f3f3f3f

struct edge{
    int to,cap,rev;
};

vector<edge> G[2*maxn];
int level[2*maxn];
int iter[2*maxn];

void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);

    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}


int dfs(int v,int t,int f){
    if(v==t) return f;

    for(int &i=iter[v];i<G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow=0;
    for(;;){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}

int N,M;
int m[maxn];
int a[maxn];
vector<int> b[maxn];

void solve(){
    int s=0,t=N+M+1;

    for(int i=1;i<=N;i++){
        add_edge(s,i,a[i]);
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<b[i].size();j++){
            add_edge(i,N+b[i][j],1);
        }
    }

    for(int i=1;i<=M;i++){
        add_edge(N+i,t,m[i]);
    }

    max_flow(s,t);

    for(int i=1;i<=M;i++){
        for(int j=0;j<G[N+i].size();j++){
            edge e=G[N+i][j];
            if(e.to!=t) continue;
            if(e.cap!=0){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main(){
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N+M+1;i++){
            G[i].clear();
        }
        for(int i=1;i<=N;i++){
            b[i].clear();
        }

        for(int i=1;i<=M;i++){
            scanf("%d",&m[i]);
        }

        for(int i=1;i<=N;i++){
            int cnt;
            scanf("%d%d",&a[i],&cnt);
            for(int j=0;j<cnt;j++){
                int x;
                scanf("%d",&x);
                b[i].push_back(x);
            }
        }
        solve();
    }
    return 0;
}
