//created by sfailsthy 2016/11/28 20:55
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =1000000+10;
int dp[maxn];

void init(){
    dp[1]=1;
    for(int i=2;i<=maxn;i++){
        if(i%2==1){
            dp[i]=dp[i-1];
        }
        else{
            dp[i]=(dp[i-1]+dp[i/2])%1000000000;
        }
    }
}

int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        printf("%d\n",dp[n]);
    }
    return 0;
}
