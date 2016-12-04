//created by sfailsthy 2016/12/4 21:11
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<double,int> P;
const int maxn =100000+10;
int N,K;
int w[maxn],v[maxn];
P y[maxn];
int opt[maxn];

bool check(double x){
    for(int i=0;i<N;i++){
        y[i]=P(v[i]-w[i]*x,i);
    }
    sort(y,y+N);

    double sum=0;
    for(int i=0;i<K;i++){
        sum+=y[N-1-i].first;
    }
    return sum>=0;
}

void solve(){
    double lb=0,ub=INF;
    for(int i=0;i<50;i++){
        double mid=(lb+ub)/2.0;
        if(check(mid)){
            lb=mid;
        }
        else{
            ub=mid;
        }
    }

    for(int i=0;i<K;i++){
        opt[i]=y[N-1-i].second+1;
    }
    sort(opt,opt+K);
    for(int i=0;i<K-1;i++){
        printf("%d ",opt[i]);
    }
    printf("%d\n",opt[K-1]);
}

int main(){
    while(scanf("%d%d",&N,&K)==2&&N){
        for(int i=0;i<N;i++){
            scanf("%d%d",&v[i],&w[i]);
        }
        solve();
    }
    return 0;
}
