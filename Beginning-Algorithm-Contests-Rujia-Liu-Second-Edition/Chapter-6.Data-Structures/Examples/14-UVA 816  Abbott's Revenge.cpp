//created by sfailsthy 2016/12/19 0:26
//话说，这个迷宫问题增加了许多处理的细节。。。QAQ
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int r,c,dir;//位置在(r,c),面朝方向dir(0-3分别代表N,E,S,W)
    Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

const int maxn =10;
const char* dirs="NESW";
const char* turns="FLR";

int has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node par[maxn][maxn][4];

int r0,c0,dir,r1,c1,r2,c2;

int dir_id(char c){
    return strchr(dirs,c)-dirs;
}

int turn_id(char c){
    return strchr(turns,c)-turns;
}

const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};

Node walk(const Node& u,int turn){
    int dir=u.dir;
    if(turn==1){
        //向左拐，逆时针
        dir=(dir+3)%4;
    }

    if(turn==2){
        //向右拐，顺时针
        dir=(dir+1)%4;
    }

    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}


bool inside(int r,int c){
    return 1<=r&&r<=9&&1<=c&&c<=9;
}

bool read_case(){
    char name[30],str[30];
    if(scanf("%s%d%d%s%d%d",name,&r0,&c0,str,&r2,&c2)!=6) return false;
    printf("%s\n",name);

    dir=dir_id(str[0]);
    r1=r0+dr[dir];
    c1=c0+dc[dir];


    memset(has_edge,0,sizeof(has_edge));
    for(;;){
        int r,c;
        scanf("%d",&r);
        if(r==0) break;
        scanf("%d",&c);
        while(scanf("%s",str)==1&&str[0]!='*'){
            for(int i=1;i<strlen(str);i++){
                has_edge[r][c][dir_id(str[0])][turn_id(str[i])]=1;
            }
        }
    }
    return true;
}

void print(Node u){
    //从目标结点逆序追溯到初始结点
    vector<Node> nodes;
    for(;;){
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir]==0) break;
        u=par[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0,c0,dir));

    int cnt=0;
    for(int i=nodes.size()-1;i>=0;i--){
        if(cnt%10==0) printf(" ");
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(nodes.size()%10!=0) printf("\n");
}

void solve(){
    queue<Node> que;
    memset(d,-1,sizeof(d));
    Node u(r1,c1,dir);
    d[u.r][u.c][u.dir]=0;
    que.push(u);

    while(!que.empty()){
        Node u=que.front();
        que.pop();
        if(u.r==r2&&u.c==c2){
            print(u);
            return;
        }

        for(int i=0;i<3;i++){
            Node v=walk(u,i);
            if(has_edge[u.r][u.c][u.dir][i]&&inside[v.r][v.c]&&d[v.r][v.c][v.dir]<0){
                par[v.r][v.c][v.dir]=u;
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                que.push(v);
            }
        }
    }

    printf("  No Solution Possible\n");
}

int main(){
    while(read_case()){
        solve();
    }
    return 0;
}
