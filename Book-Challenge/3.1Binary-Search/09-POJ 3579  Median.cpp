//created by sfailsthy 2016/12/4 21:45
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> P;
const int maxn =100000+10;
int N,M;
int X[maxn];

bool check(int x){
    int cnt=0;
    for(int i=0;i<N;i++){
        cnt+=N-(lower_bound(X+i+1,X+N,X[i]+x)-X);
    }
    return cnt<=M;
}

void solve(){
    M=N*(N-1)/4;
    sort(X,X+N);
    int lb=0,ub=X[N-1]-X[0];
    while(ub-lb>1){
        int mid=(lb+ub)>>1;
        if(check(mid)){
            ub=mid;
        }
        else{
            lb=mid;
        }
    }
    printf("%d\n",lb);
}

int main(){
    while(scanf("%d",&N)!=EOF&&N){
        for(int i=0;i<N;i++){
            scanf("%d",&X[i]);
        }
        solve();
    }
    return 0;
}
