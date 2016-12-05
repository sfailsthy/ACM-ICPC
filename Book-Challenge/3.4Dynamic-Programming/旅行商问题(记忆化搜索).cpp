//created by sfailsthy 2016/12/5 14:42
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

int rec(int S,int v){
    if(dp[S][v]>=0){
        return dp[S][v];
    }

    if(S==(1<<n)-1&&v==0){
        return dp[S][v]=0;
    }

    int res=INF;
    for(int u=0;u<n;u++){
        if(!(S>>u&1)){
            res=min(res,rec(S|1<<u,u)+d[v][u]);
        }
    }
    return dp[S][v]=res;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=c;
    }
    int ans=rec(0,0);
    if(ans==INF) ans=-1;
    printf("%d\n",ans);
    return 0;
}
