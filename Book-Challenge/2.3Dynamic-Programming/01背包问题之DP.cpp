//created by sfailsthy 2016/11/28 15:31
//时间复杂度为O(nW)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn =100+10;
const int maxw =10000+10;
int n,W;
int w[maxn],v[maxn];
int dp[maxn][maxw];

void solve(){
    memset(dp[n],0,sizeof(dp[n]));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp[i][j]=dp[i+1][j];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[0][W]);
}

int main(){
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    solve();
    return 0;
}
