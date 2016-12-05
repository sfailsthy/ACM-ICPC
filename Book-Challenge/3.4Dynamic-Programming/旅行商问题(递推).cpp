//created by sfailsthy 2016/12/5 14:48
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =16;

int n,m;
int d[maxn][maxn];
int dp[1<<maxn][maxn];

void solve(){
    memset(dp,0x3f,sizeof(dp));
    dp[(1<<n)-1][0]=0;

    for(int S=(1<<n)-2;S>=0;S--){
        for(int v=0;v<n;v++){
            for(int u=0;u<n;u++){
                if(!(S>>u&1)){
                    dp[S][v]=min(dp[S][v],dp[S|1<<u][u]+d[v][u]);
                }
            }
        }
    }
    if(dp[0][0]==INF) dp[0][0]=-1;
    printf("%d\n",dp[0][0]);
}

int main(){
    scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=c;
    }
    solve();
    return 0;
}
