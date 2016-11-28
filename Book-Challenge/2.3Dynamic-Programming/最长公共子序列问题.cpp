//created by sfailsthy 2016/11/28 18:56
//LCS问题
//时间复杂度为O(nm)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn =1000+10;

int n,m;
char s[maxn],t[maxn];
int dp[maxn][maxn];
//dp[i][j]表示字符数组s前i个与字符数组t前j个的最长公共子序列的长度

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }

            else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main(){
    scanf("%d%d",&n,&m);
    cin>>s>>t;
    solve();
    return 0;
}
