//created by sfailsthy 2016/11/28 19:04
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn =100+10;
const int maxw =10000+10;
int n,W;
int w[maxn],v[maxn];
int dp[maxn][maxw];

//dp[i+1][j]=max(dp[i][j-k*w[i]]+k*v[i]);//k>=0
void solve(){
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            for(int k=0;k*w[i]<=j;k++){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*w[i]]+k*v[i]);
            }
        }
    }
    printf("%d\n",dp[n][W]);
}

int main(){
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    solve();
    return 0;
}
