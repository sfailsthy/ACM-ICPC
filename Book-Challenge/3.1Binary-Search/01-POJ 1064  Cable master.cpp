//created by sfailsthy 2016/12/5 14:29
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =10000+10;
int n,k;
double L[maxn];

bool check(double x){
    int num=0;
    for(int i=0;i<n;i++){
        num+=(int)(L[i]/x);
    }
    return num>=k;
}

void solve(){
    double lb=0.0,ub=INF;
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2;
        if(check(mid)){
            lb=mid;
        }
        else{
            ub=mid;
        }
    }
    printf("%.2f\n",floor(100*lb)/100);
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>L[i];
    }
    solve();
    return 0;
}
