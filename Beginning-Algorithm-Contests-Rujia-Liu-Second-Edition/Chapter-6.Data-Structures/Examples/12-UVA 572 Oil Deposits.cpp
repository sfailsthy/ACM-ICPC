//created by sfailsthy 2016/10/29 2:21
#include <iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;

const int maxn =100+10;
char grid[maxn][maxn];
int m,n;
int res;

void dfs(int x,int y)
{
    grid[x][y]='*';
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            int nx=x+dr,ny=y+dc;
            if(dr==0&&dc==0) continue;
            if(nx<0||nx>=m||ny<0||ny>=n) continue;
            if(grid[nx][ny]=='@'){
                dfs(nx,ny);
            }
        }
    }
}
int main()
{
    while(cin>>m>>n&&m&&n){
        for(int i=0;i<m;i++){
            scanf("%s",grid[i]);
        }
        res=0;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]=='@'){
                    dfs(x,y);
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
