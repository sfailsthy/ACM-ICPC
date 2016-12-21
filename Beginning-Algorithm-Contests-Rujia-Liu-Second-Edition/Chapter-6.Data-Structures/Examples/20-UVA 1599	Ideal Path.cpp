//created by sfailsthy 2016/12/19 1:33
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn =1e5+10;

struct edge{
    int to,color;
};

vector<edge> G[maxn];
int d[maxn];
int vis[maxn];
int n,m;

void rev_bfs(){
    memset(d,-1,sizeof(d));
    d[n]=0;
    queue<int> que;
    que.push(n);

    while(!que.empty()){
        int u=que.front();
        que.pop();

        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].to;
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            que.push(v);
        }
    }
}

void bfs(){
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    vector<int> next;
    next.push_back(1);

    vector<int> ans;
    for(int i=0;i<d[1];i++){
        int temp=INF;
        for(int j=0;j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                edge e=G[u][k];
                int v=e.to,color=e.color;
                if(d[v]==d[u]-1){
                    temp=min(temp,color);
                }
            }
        }

        ans.push_back(temp);

        vector<int> next2;
        for(int j=0;j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                edge e=G[u][k];
                int v=e.to,color=e.color;
                if(d[v]==d[u]-1&&!vis[v]&&color==temp){
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
        for(int i=1;i<=n;i++){
            G[i].clear();
        }

        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back((edge){b,c});
            G[b].push_back((edge){a,c});
        }
        rev_bfs();
        bfs();
    }
    return 0;
}
