//created by sfailsthy 2016/11/17 18:36

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn =100+10;

char field[maxn][maxn];
int n,m;

void dfs(int x,int y){
    field[x][y]='.';

    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx;
            int ny=y+dy;

            if(nx>=0&&nx<n&&ny>=0&&ny<m&&field[nx][ny]=='W'){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>field[i];
    }

    int cnt=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(field[x][y]=='W'){
                dfs(x,y);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}
