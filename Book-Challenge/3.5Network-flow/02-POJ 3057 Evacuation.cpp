//created by sfailsthy 2016/12/11 1:58
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn =15;

//二分图的最大匹配
int V;
vector<int> G[8000+10];
int match[8000+10];
bool used[8000+10];

void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

int bitpartite_matching(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++){
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}
////


const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int X,Y;
char field[maxn][maxn];

vector<int> dX,dY;//门的坐标
vector<int> pX,pY;//人的坐标
int dist[maxn][maxn][maxn][maxn];//距离

//判断所有人能否在时间t内逃脱
bool check(int t){
    int d=dX.size(),p=pX.size();
    //0-d-1:时间1对应的门
    //d-2d-1:时间2对应的门
    //……
    //(t-1)d-td-1:时间t对应的门
    //td-td+p-1://人
    V=t*d+p;
    for(int v=0;v<V;v++){
        G[v].clear();
    }

    for(int i=0;i<d;i++){
        for(int j=0;j<p;j++){
            if(dist[dX[i]][dY[i]][pX[j]][pY[j]]>=0){
                for(int k=dist[dX[i]][dY[i]][pX[j]][pY[j]];k<=t;k++){
                    add_edge((k-1)*d+i,t*d+j);
                }
            }
        }
    }
    return bitpartite_matching()==p;
}

//通过bfs计算最短距离
void bfs(int x,int y,int d[maxn][maxn]){
    queue<int> qx,qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);
    while(!qx.empty()){
        x=qx.front();qx.pop();
        y=qy.front();qy.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(0<=nx&&nx<X&&0<=ny&&ny<Y&&field[nx][ny]=='.'&&d[nx][ny]<0){
                d[nx][ny]=d[x][y]+1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void solve(){
    int n=X*Y;
    dX.clear();dY.clear();
    pX.clear();pY.clear();
    memset(dist,-1,sizeof(dist));
    for(int x=0;x<X;x++){
        for(int y=0;y<Y;y++){
            if(field[x][y]=='D'){
                dX.push_back(x);
                dY.push_back(y);
                bfs(x,y,dist[x][y]);
            }

            else if(field[x][y]=='.'){
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }

    int lb=-1,ub=n+1;
    while(ub-lb>1){
        int mid=(lb+ub)>>1;
        if(check(mid)){
            ub=mid;
        }
        else{
            lb=mid;
        }
    }

    if(ub>n){
        printf("impossible\n");
    }
    else{
        printf("%d\n",ub);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&X,&Y);
        for(int i=0;i<X;i++){
            scanf("%s",field[i]);
        }
        solve();
    }
    return 0;
}
