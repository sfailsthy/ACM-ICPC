#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =1000+10;
int N,K;
int a[maxn],b[maxn];
double y[maxn];

bool check(double x){
    for(int i=0;i<N;i++){
        y[i]=a[i]-b[i]*x;
    }
    sort(y,y+N);

    double sum=0;
    for(int i=0;i<N-K;i++){
        sum+=y[N-1-i];
    }
    return sum>=0;
}

void solve(){
    double lb=0,ub=1;
    while(abs(lb-ub)>1e-4){
        double mid=(lb+ub)/2.0;
        if(check(mid)){
            lb=id;
        }
        else{
            ub=mid;
        }
    }

    printf("%d\n",(int)(100*lb+0.5));
}

int main(){
    while(cin>>N>>K&&N){
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            cin>>b[i];
        }
        solve();
    }
    return 0;
}
