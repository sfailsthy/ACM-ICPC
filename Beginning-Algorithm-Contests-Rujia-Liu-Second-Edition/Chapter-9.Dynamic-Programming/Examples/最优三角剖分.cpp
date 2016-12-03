//created by sfailsthy 2016/12/3 23:26
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =1000+10;
int n;
int v[maxn];
int dp[maxn][maxn];

inline int w(int i,int j,int k){
    if(i==j||i==k||j==k) return 0;
    else{
        return v[i]+v[j]+v[k];
    }
}

int f(int i,int j){
    if(dp[i][j]>=0) return dp[i][j];
    int &ans=dp[i][j];
    ans=-INF;
    for(int k=i+1;k<j;k++){
        ans=max(ans,f(i,k)+f(k,j)+w(i,j,k));
    }
    return ans;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=0;
        }
        printf("%d\n",f(0,n-1));
    }
    return 0;
}
