//created by sfailsthy 2016/11/17 18:45

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn =20+10;
char field[maxn][maxn];
int H,W;

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int cnt;

void dfs(int x,int y){
    field[x][y]='#';

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<H&&ny>=0&&ny<W&&field[nx][ny]=='.'){
            dfs(nx,ny);
            cnt++;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(cin>>W>>H&&H&&W){
        int sx,sy;

        for(int i=0;i<H;i++){
            cin>>field[i];
            for(int j=0;j<W;j++){
                if(field[i][j]=='@'){
                    sx=i;
                    sy=j;
                    break;
                }
            }
        }

        cnt=0;
        dfs(sx,sy);
        cout<<cnt+1<<endl;
    }
    return 0;
}
