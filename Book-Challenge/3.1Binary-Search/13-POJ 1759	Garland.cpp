//created by sfailsthy 2016/12/5 1:52
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long LL;

const int maxn =1000+10;
int N;
double A,B,H[maxn];

bool check(double x){
    H[1]=x;
    for(int i=2;i<N;i++){
        H[i]=2*(H[i-1]+1)-H[i-2];
        if(H[i]<0){
            return false;
        }
    }
    B=H[N-1];
    return true;
}

void solve(){
    double lb=-1,ub=maxn;
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2.0;
        if(check(mid)){
            ub=mid;
        }
        else{
            lb=mid;
        }
    }
    printf("%.2f\n",B);
}

int main(){
    cin>>N>>A;
    H[0]=A;
    solve();
    return 0;
}
