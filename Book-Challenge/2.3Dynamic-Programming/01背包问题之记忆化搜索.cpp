//created by sfailsthy 2016/15/27
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
int dp[maxn][maxw];//

int rec(int i,int j){
    if(dp[i][j]>=0){
        return dp[i][j];
    }

    int res;
    if(i==n){
        res=0;
    }

    else if(j<w[i]){
        res=rec(i+1,j);
    }

    else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }

    return res;
}

int main(){
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",rec(0,W));
    return 0;
}
