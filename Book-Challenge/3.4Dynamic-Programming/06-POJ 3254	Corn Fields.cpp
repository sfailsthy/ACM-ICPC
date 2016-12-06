//created by sfailsthy 2016/12/6 13:36
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Mod=1e8;
const int maxn =13;
int field[maxn];
int dp[maxn][1<<maxn];
int state[1<<maxn];
int n,m;

void solve(){
    int cnt=0;
    for(int x=0;x<(1<<n);x++){
        if(!(x&(x<<1))){
            state[cnt++]=x;
        }
    }

    for(int i=0;i<cnt;i++){
        if(!(field[0]&state[i])){
            dp[0][i]=1;
        }
    }

    for(int i=1;i<m;i++){
        for(int j=0;j<cnt;j++){
            if(field[i]&state[j]) continue;
            for(int k=0;k<cnt;k++){
                if(field[i-1]&state[k]) continue;
                if(state[j]&state[k]) continue;
                dp[i][j]+=dp[i-1][k];
            }
        }
    }

    int res=0;
    for(int i=0;i<cnt;i++){
        res+=dp[m-1][i];
        res%=Mod;
    }
    printf("%d\n",res);
}

int main(){
    scanf("%d%d",&m,&n);
    memset(dp,0,sizeof(dp));
    memset(field,0,sizeof(field));
    memset(state,0,sizeof(state));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x;
            scanf("%d",&x);
            if(x==0){
                field[i]+=1<<(n-1-j);
            }
        }
    }
    solve();
    return 0;
}
