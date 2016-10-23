#include<iostream>  
#include<cstdio>  
#include<queue>  
#include<utility>  
using namespace std;  
typedef pair<int,int> P;  
#define INF 0x7fffffff  
char maze[5][5];  
int sx,sy;//起点坐标  
int gx,gy;//终点坐标  
int d[5][5];//起点到各个位置的最短距离数组  
P father[5][5];  
int dx[]={1,-1,0,0};  
int dy[]={0,0,1,-1};  
//求(sx,sy)到(gx,gy)的最短距离  
int bfs()  
{  
    queue<P> que;  
    for(int i=0;i<5;i++){  
        for(int j=0;j<5;j++){  
            d[i][j]=INF;  
        }  
    }  
    que.push(P(sx,sy));  
    d[sx][sy]=0;  
    while(que.size()){  
        P p=que.front();  
        que.pop();  
        if(p.first==gx&&p.second==gy) break;  
        //四个方向的循环  
        for(int i=0;i<4;i++){  
            int nx=p.first+dx[i];  
            int ny=p.second+dy[i];  
            //判断是否可以移动，以及是否已访问过  
            if(0<=nx&&nx<5&&ny>=0&&ny<5&&maze[nx][ny]!='1'&&d[nx][ny]==INF){  
                que.push((P(nx,ny)));  
                father[nx][ny]=p;  
                d[nx][ny]=d[p.first][p.second]+1;  
            }  
        }  
    }  
    return d[gx][gy];  
}  
void solve(P p)  
{  
    if(p.first==sx&&p.second==sy){  
        cout<<"("<<sx<<", "<<sy<<")"<<endl;  
        return;  
    }  
    else{  
        solve(father[p.first][p.second]);  
        cout<<"("<<p.first<<", "<<p.second<<")"<<endl;  
    }  
}  
int main()  
{  
    for(int i=0;i<5;i++){  
        for(int j=0;j<5;j++){  
            cin>>maze[i][j];  
        }  
    }  
    sx=0;sy=0;  
    gx=4;gy=4;  
    int res=bfs();  
    //printf("%d\n",res);  
    P p(gx,gy);  
    solve(p);  
    return 0;  
}  
