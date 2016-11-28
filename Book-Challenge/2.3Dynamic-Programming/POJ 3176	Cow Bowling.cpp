//created by sfailsthy 2016/11/28 20:14
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn =400+10;

int n;
int a[maxn][maxn];
int dp[maxn][maxn];

void solve(){
    memset(dp[n+1],0,sizeof(dp[n+1]));

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    solve();
    return 0;
}
