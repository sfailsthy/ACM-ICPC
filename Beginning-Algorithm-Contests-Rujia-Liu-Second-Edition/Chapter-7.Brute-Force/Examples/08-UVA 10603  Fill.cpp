//created by sfailsthy 2016/12/18 21:49
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int v[3],dist;
    bool operator < (const Node& rhs) const{
        return dist>rhs.dist;
    }
};

const int maxn =200+10;
int vis[maxn][maxn];
int cap[3],ans[maxn];

void update_ans(const Node& u){
    for(int i=0;i<3;i++){
        int d=u.v[i];
        if(ans[d]<0||u.dist<ans[d]){
            ans[d]=u.dist;
        }
    }
}

void bfs(int a,int b,int c,int d){
    cap[0]=a;cap[1]=b;cap[2]=c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<Node> que;

    Node start;
    start.dist=0;
    start.v[0]=0;start.v[1]=0;start.v[2]=c;
    vis[0][0]=1;
    que.push(start);

    while(!que.empty()){
        Node u=que.top();
        que.pop();
        update_ans(u);
        if(ans[d]>=0) break;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    if(u.v[i]==0||u.v[j]==cap[j]) continue;
                    int amount=min(cap[j],u.v[i]+u.v[j])-u.v[j];
                    Node u2;
                    memcpy(&u2,&u,sizeof(u));
                    u2.dist=u.dist+amount;
                    u2.v[i]-=amount;
                    u2.v[j]+=amount;
                    if(!vis[u2.v[0]][u2.v[1]]){
                        vis[u2.v[0]][u2.v[1]]=1;
                        que.push(u2);
                    }
                }
            }
        }
    }

    while(d>=0){
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}

int main(){
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        bfs(a,b,c,d);
    }
    return 0;
}
