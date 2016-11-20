//created by sfailsthy 2016/11/20 20:46
//按照奶酪硬度从1到n的顺序吃，否则会体力不支。实际上就是求从S到1，到2，到3，直到n的最短路径。bfs。
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
#include <cctype>
using namespace std;
const int maxn =1000+10;
typedef pair<int,int> P;

int H,W,n;
char field[maxn][maxn];
int d[maxn][maxn];
P factory[10];

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int bfs(int sx,int sy,int gx,int gy){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            d[i][j]=-1;
        }
    }

    queue<P> que;
    que.push(P(sx,sy));
    d[sx][sy]=0;

    while(!que.empty()){
        P p=que.front();
        que.pop();
        int x=p.first;
        int y=p.second;

        if(x==gx&&y==gy){
            return d[gx][gy];
        }

        else{
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<H&&ny>=0&&ny<W&&field[nx][ny]!='X'&&d[nx][ny]==-1){
                    que.push(P(nx,ny));
                    d[nx][ny]=d[x][y]+1;
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(cin>>H>>W>>n){

        for(int i=0;i<H;i++){
            cin>>field[i];
            for(int j=0;j<W;j++){
                if(field[i][j]=='S'){
                    factory[0].first=i;
                    factory[0].second=j;
                    field[i][j]='.';
                }

                else if(isdigit(field[i][j])){
                    int index=field[i][j]-'0';
                    factory[index].first=i;
                    factory[index].second=j;
                }
            }
        }

        int step=0;
        for(int i=0;i<n;i++){
            step+=bfs(factory[i].first,factory[i].second,factory[i+1].first,factory[i+1].second);
        }
        cout<<step<<endl;
    }
    return 0;
}
