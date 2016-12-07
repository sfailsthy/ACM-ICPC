//created by sfailtshy 2016/12/8 1:39
//注意顶点个数最大是400
//32ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =100+10;

//(终点、容量反向边)
struct edge{
    int to,cap,rev;
};

vector<edge> G[4*maxn];//图的邻接表表示
bool used[4*maxn];//DFS中用到的标记

//向图中增加一条从s到t容量为cap的边
void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

//通过DFS寻找增广路
int dfs(int v,int t,int f){
    if(v==t) return f;
    used[v]=true;

    for(int i=0;i<G[v].size();i++){
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0){
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

//求解从s到t的最大流
int max_flow(int s,int t){
    int flow=0;
    for(;;){
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}

int N,F,D;
bool likeF[maxn][maxn];//食物的喜好
bool likeD[maxn][maxn];//饮料的喜好

void solve(){
    //0-N-1:食物一侧的牛
    //N-2N-1:饮料一侧的牛
    //2N-2N+F-1:食物
    //2N+F-2N+F+D-1:饮料
    int s=2*N+F+D,t=s+1;

    //在s和食物之间连边
    for(int i=0;i<F;i++){
        add_edge(s,2*N+i,1);
    }

    //在饮料和t之间连边
    for(int i=0;i<D;i++){
        add_edge(2*N+F+i,t,1);
    }

    for(int i=0;i<N;i++){
        //在食物一侧的牛和饮料一侧的牛之间连边
        add_edge(i,N+i,1);

        //在牛和所喜欢的食物之间连边
        for(int j=0;j<F;j++){
            if(likeF[i][j]){
                add_edge(2*N+j,i,1);
            }
        }

        //在牛和所喜欢的饮料之间连边
        for(int j=0;j<D;j++){
            if(likeD[i][j]){
                add_edge(N+i,2*N+F+j,1);
            }
        }

    }

    printf("%d\n",max_flow(s,t));
}


int main(){
    scanf("%d%d%d",&N,&F,&D);
    memset(likeD,0,sizeof(likeD));
    memset(likeF,0,sizeof(likeF));
    for(int i=0;i<N;i++){
        int Fi,Di;
        scanf("%d%d",&Fi,&Di);
        for(int j=0;j<Fi;j++){
            int f;
            scanf("%d",&f);
            likeF[i][f-1]=1;
        }

        for(int j=0;j<Di;j++){
            int d;
            scanf("%d",&d);
            likeD[i][d-1]=1;
        }
    }

    solve();
    return 0;
}
