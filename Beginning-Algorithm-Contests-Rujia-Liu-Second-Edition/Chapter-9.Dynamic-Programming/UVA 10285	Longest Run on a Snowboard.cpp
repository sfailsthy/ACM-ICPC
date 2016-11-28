//created by sfailsthy 2016/11/29 0:43
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int maxn =100+10;
int R,C;
int field[maxn][maxn];
int dp[maxn][maxn];
string s;

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int d(int x,int y){
    int& ans=dp[x][y];
    if(ans>0) return ans;

    ans=1;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=R||ny<0||ny>=C) continue;

        if(field[nx][ny]<field[x][y]){
            ans=max(ans,d(nx,ny)+1);
        }
    }

    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>s;
        scanf("%d%d",&R,&C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&field[i][j]);
            }
        }

        memset(dp,0,sizeof(dp));
        int res=0;
        for(int x=0;x<R;x++){
            for(int y=0;y<C;y++){
                res=max(res,d(x,y));
            }
        }
        cout<<s;
        printf(": %d\n",res);
    }
    return 0;
}
