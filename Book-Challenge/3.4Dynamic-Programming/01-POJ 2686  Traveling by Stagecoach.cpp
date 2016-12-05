//created by sfailsthy 2016/12/5 23:31
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =10;
const int maxm =35;

int n,m,p,a,b;
int t[maxn];
int d[maxm][maxm];

//dp[S][v]表示从a点开始到达v点剩下的车票集合为S的状态所需要的最小花费
double dp[1<<maxn][maxm];

void solve(){
    for(int i=0;i<(1<<n);i++){
        fill(dp[i],dp[i]+m,INF);
    }
    dp[(1<<n)-1][a-1]=0;

    double res=INF;
    for(int S=(1<<n)-1;S>=0;S--){
        res=min(res,dp[S][b-1]);
        for(int v=0;v<m;v++){
            for(int i=0;i<n;i++){
                if(S>>i&1){
                    for(int u=0;u<m;u++){
                        if(d[v][u]>=0){
                            dp[S&~(1<<i)][u]=min(dp[S&~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }

    if(res==INF){
        printf("Impossible\n");
    }
    else{
        printf("%.3f\n", res);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)==5&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&t[i]);
        }

        memset(d,-1,sizeof(d));
        for(int i=0;i<m;i++){
            d[i][i]=0;
        }
        for(int i=0;i<p;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            d[a][b]=d[b][a]=c;
        }
        solve();
    }
    return 0;
}
