//created by sfailsthy 2016/12/2 0:28
#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
typedef pair<double,double> P;

const int maxn =1e5+10;
int N;
P A[maxn];

//用于按照坐标归并的函数
bool compare_y(P a,P b){
    return a.second<b.second;
}

double closest_pair(P *a,int n){
    if(n<=1) return INF;
    int m=n/2;
    double x=a[m].first;
    double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
    inplace_merge(a,a+m,a+n,compare_y);

    vector<P> b;
    for(int i=0;i<n;i++){
        if(fabs(a[i].first-x)>=d) continue;

        //从后往前检查b中y坐标相差小于d的点
        for(int j=0;j<b.size();j++){
            double dx=a[i].first-b[b.size()-j-1].first;
            double dy=a[i].second-b[b.size()-j-1].second;
            if(dy>=d) break;
            d=min(d,sqrt(dx*dx+dy*dy));
        }
        b.push_back(a[i]);
    }

    return d;
}

void solve(){
    sort(A,A+N);
    double ans=closest_pair(A,N);
    if(ans>=10000) printf("INFINITY\n");
    else printf("%.4f\n",ans);
}

int main(){
    while(scanf("%d",&N)!=EOF&&N){
        for(int i=0;i<N;i++){
            cin>>A[i].first>>A[i].second;
        }
        solve();
    }
    return 0;
}
