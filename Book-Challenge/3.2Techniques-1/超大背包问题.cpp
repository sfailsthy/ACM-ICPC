//created by sfailsthy 2016/11/29 13:28
/*
01背包问题，但是限制条件是1<=n<=40,1<=w[i],v[i]<=10^15,1<=W<=10^15
时间复杂度为O(2^(n/2)n).
*/
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <cstdio>
using namespace std;
typedef long long LL;
#define INF numeric_limits<LL>::max()

const int maxn =40+10;
int n;
LL w[maxn],v[maxn];
LL W;
pair<LL,LL> ps[1<<(maxn/2)];//(重量，价值)

void solve(){
    //枚举前半部分
    int n2=n/2;
    for(int i=0;i<(1<<n2);i++){
        LL sw=0,sv=0;
        for(int j=0;j<n2;j++){
            if((i>>j)&1){
                sw+=w[j];
                sv+=v[j];
            }
        }
        ps[i]=make_pair(sw,sv);
    }

    //去除多余的元素
    sort(ps,ps+(1<<n2));
    int m=1;
    for(int i=1;i<(1<<n2);i++){
        if(ps[m-1].second<ps[i].second){
            ps[m++]=ps[i];
        }
    }

    //枚举后半部分求解
    LL res=0;
    for(int i=0;i<1<<(n-n2);i++){
        LL sw=0,sv=0;
        for(int j=0;j<n-n2;j++){
            if(i>>j&1){
                sw+=w[n2+j];
                sv+=v[n2+j];
            }
        }

        if(sw<=W){
            LL tv=(lower_bound(ps,ps+m,make_pair(W-sw,INF))-1)->second;
            res=max(res,sv+tv);
        }
    }
    printf("%lld\n",res);
}

int main(){
    scanf("%d%lld",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&w[i],&v[i]);
    }
    solve();
    return 0;
}
