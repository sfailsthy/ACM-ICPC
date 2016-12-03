//created by sfailsthy 2016/12/3 17:2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn =1000+10;
#define INF 0x3f3f3f3f

int n;
int p[maxn];
int dp[maxn][maxn];
int f(int i,int j){
    if(i==j) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    int &ans=dp[i][j];
    ans=INF;
    for(int k=i;k<j;k++){
        ans=min(ans,f(i,k)+f(k+1,j)+p[i-1]*p[k]*p[j]);
    }
    return ans;
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<=n;i++){
            scanf("%d",&p[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",f(1,n));
    }
    return 0;
}
/*
Sample Input
3
10 100 5 50
6
30 35 15 5 10 20 25
0
Sample Output
7500
15125
*/
