//created by sfailsthy 2016/12/3 23:39
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =50+10;
int n;
int x[maxn];
int L;
int dp[maxn][maxn];

int f(int i,int j){
    if(dp[i][j]>0) return dp[i][j];
    if(j==i+1) return dp[i][j]=x[j]-x[i];
    int &ans=dp[i][j];
    ans=INF;
    for(int k=i+1;k<j;k++){
        ans=min(ans,f(i,k)+f(k,j)+x[j]-x[i]);
    }
    return ans;
}

int main(){
    while(scanf("%d",&L)!=EOF&&L){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        x[0]=0;
        x[n+1]=L;
        memset(dp,0,sizeof(dp));
        printf("The minimum cutting is %d.\n",f(0,n+1)-L);
    }
    return 0;
}
