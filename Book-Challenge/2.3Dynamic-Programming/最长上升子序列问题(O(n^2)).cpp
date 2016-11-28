//created by sfailsthy 2016/11/28 19:52
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =1000+10;

int n;
int a[maxn];
int dp[maxn];
//dp[i]表示以a[i]结尾的最长上升子序列长度

void solve(){
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    printf("%d\n",res);

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
