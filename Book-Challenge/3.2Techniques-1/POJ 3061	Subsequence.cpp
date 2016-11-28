//created by sfailsthy 2016/11/29 1:42
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn =100000+10;
int n,S;
int a[maxn];

void solve(){
    int res=n+1;
    int s=0,t=0,sum=0;
    for(;;){
        while(t<n&&sum<S){
            sum+=a[t++];
        }
        if(sum<S){
            break;
        }
        res=min(res,t-s);
        sum-=a[s++];
    }

    if(res>n){
        res=0;
    }
    printf("%d\n",res);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&S);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}
