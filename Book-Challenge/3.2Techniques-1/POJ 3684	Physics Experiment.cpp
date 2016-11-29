#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn =100+10;
const double g=10.0;

int n,H,R,T;
double y[maxn];

double calc(int T){
    if(T<0) return H;
    double t=sqrt(2*H/g);
    int k=(int)(T/t);
    if(k&1){
        double t1=k*t+t-T;
        return H-g*t1*t1/2;
    }

    else{
        double t1=T-k*t;
        return H-g*t1*t1/2;
    }
}

void solve(){
    for(int i=0;i<n;i++){
        y[i]=calc(T-i);
    }

    sort(y,y+n);
    for(int i=0;i<n;i++){
        printf("%.2f%c", y[i]+2*R*i/100.0,i+1==n?'\n':' ');
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&H,&R,&T);
        solve();
    }
    return 0;
}
