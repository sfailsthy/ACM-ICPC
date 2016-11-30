//created by sfailsthy 2016/11/29 1:42

//二分搜索，时间复杂度为O(nlogn)
#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const int maxn =1e5+10;
int n,S;
int a[maxn];
int sum[maxn];

void solve(){
    sum[0]=0;
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+a[i];
    }

    if(sum[n]<S){
        printf("0\n");
        return;
    }

    int res=n;
    for(int s=0;sum[s]+S<=sum[n];s++){
        int t=lower_bound(sum,sum+n,sum[s]+S)-sum;
        res=min(res,t-s);
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

//尺取法，时间复杂度为O(n)
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
