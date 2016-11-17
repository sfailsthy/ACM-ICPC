//created by sfailsthy 2016/11/17 18:38

#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> P;
#define INF 0x7fffffff

int field[5][5];
int d[5][5];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};
P father[5][5];

int bfs(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            d[i][j]=INF;
        }
    }

    queue<P> que;
    que.push(P(0,0));
    d[0][0]=0;

    while(!que.empty()){
        P p=que.front();
        que.pop();
        int x=p.first;
        int y=p.second;

        if(x==4&&y==4) return d[4][4];

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0&&nx<5&&ny>=0&&ny<5&&!field[nx][ny]&&d[nx][ny]==INF){
                que.push(P(nx,ny));
                d[nx][ny]=d[x][y]+1;
                father[nx][ny]=p;
            }
        }
    }
}


void path(P p){
    if(p.first==0&&p.second==0){
        cout<<"("<<0<<", "<<0<<")"<<endl;
        return;
    }
    else{
        path(father[p.first][p.second]);
        cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>field[i][j];
        }
    }

    int res=bfs();
    path(P(4,4));
    return 0;
}
