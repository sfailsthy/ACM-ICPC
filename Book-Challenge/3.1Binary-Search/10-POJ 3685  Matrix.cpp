//created by sfailsthy 2016/12/5 1:09
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL N,M;
inline LL f(LL i,LL j){
    return i*i+100000*i+j*j-100000*j+i*j;
}

bool check(LL x){
    LL cnt=0;
    for(int j=1;j<=N;j++){
        int lb=0,ub=N+1;
        while(ub-lb>1){
            int i=(lb+ub)>>1;
            if(f(i,j)<x){
                lb=i;
            }
            else{
                ub=i;
            }
        }
        cnt+=lb;
    }
    return cnt<M;
}

void solve(){
    LL lb=-100000*N,ub=100000*N+3*N*N;
    while(ub-lb>1){
        LL mid=(lb+ub)>>1;
        if(check(mid)){
            lb=mid;
        }
        else{
            ub=mid;
        }
    }
    printf("%lld\n",lb);
}

int main(){
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        solve();
    }
    return 0;
}
