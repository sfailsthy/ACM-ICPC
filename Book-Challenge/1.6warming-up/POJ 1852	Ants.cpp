//created by sfailsthy 2016/11/20 20:07
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn =1e6+10;

int L,n;
int x[maxn];

void solve(){
    int minT=0,maxT=0;

    for(int i=0;i<n;i++){
        minT=max(minT,min(x[i],L-x[i]));
        maxT=max(maxT,max(x[i],L-x[i]));
    }

    printf("%d %d\n", minT,maxT);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&L,&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        solve();
    }
    return 0;
}
