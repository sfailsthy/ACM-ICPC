//created by sfailsthy 2016/12/12 19:42
#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
const int maxn =100+10;
int n,W;
int w[maxn],v[maxn],m[maxn];
int dp[10*maxn];

void solve(){
    for(int i=0;i<n;i++){
        int num=m[i];
        for(int k=1;num>0;k<<=1){
            int mul=min(mul,k);
            for(int j=W;j>=w[i]*mul;j--){
                dp[j]=max(dp[j],dp[j-w[i]*mul]+mul*v[i]);
            }
            num-=mul;
        }
    }
    printf("%d\n",dp[W]);
}

int main(){
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&w[i],&v[i],&m[i]);
    }
    solve();
    return 0;
}
