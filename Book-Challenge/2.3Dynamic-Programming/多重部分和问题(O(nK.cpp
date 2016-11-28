//created by sfailsthy 2016/11/28 19:38
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
int dp[maxk];
//dp[i][j]表示用前i种数字加成j时第i中数字最多剩余多少个
//采用滚动数组

void solve(){
    memset(dp,-1,sizeof(dp));
    dp[0]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            if(dp[j]>=0){
                dp[j]=m[i];
            }
            else if(j<a[i]||dp[j-a[i]]<=0){
                dp[j]=-1;
            }
            else{
                dp[j]=dp[j-a[i]]-1;
            }
        }
    }

   if(dp[K]>=0) printf("YES\n");
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
