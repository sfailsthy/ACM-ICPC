//created by sfailsthy 2016/11/3 23:28
#include <iostream>
#include<cstring>
#include<string>
#include<utility>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> P;

const int maxn =10;
int mark[maxn][maxn];
int step[maxn][maxn];
int sx,sy;
int gx,gy;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

int bfs()
{
    memset(mark,0,sizeof(mark));
    queue<P> que;
    que.push(P(sx,sy));
    mark[sx][sy]=1;
    step[sx][sy]=0;
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        if(x==gx&&y==gy) return step[gx][gy];
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<=0||nx>8||ny<=0||ny>8) continue;
            if(!mark[nx][ny]){
               que.push(P(nx,ny));
               step[nx][ny]=step[x][y]+1;
               mark[nx][ny]=1;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string str1,str2;
    while(cin>>str1>>str2){
        sx=str1[0]-'a'+1;
        sy=str1[1]-'0';
        gx=str2[0]-'a'+1;
        gy=str2[1]-'0';
        cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<bfs()<<" knight moves."<<endl;
    }
    return 0;
}
