//created by sfailsthy 2016/11/28 19:31
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =100+10;
const int maxk =100000+10;
int n,K;
int a[maxn],m[maxn];
bool dp[maxn][maxk];
//dp[i][j]表示用前i中数字能否加成j

void solve(){
    dp[0][0]=true;

    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=m[i]&&k*a[i]<=j;k++){
                dp[i+1][j]|=dp[i][j-k*a[i]];
            }
        }
    }

    if(dp[n][K]) printf("YES\n");
    else printf("NO\n");
}

int main(){
    scanf("%d%d",&n,&K);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&m[i]);
    }
    solve();
    return 0;
}
