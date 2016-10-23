#include<iostream>  
#include<cstdio>  
#include<vector>  
#include<cstring>  
#include<algorithm>  
#include<utility>  
#include<queue>  
using namespace std;  
  
#define MAX_N 805  
typedef long long ll;  
  
int n;  
int v1[MAX_N],v2[MAX_N];  
void solve()  
{  
    sort(v1,v1+n);  
    sort(v2,v2+n);  
    ll ans=0;  
    for(int i=0;i<n;i++){  
        ans+=(ll)v1[i]*v2[n-1-i];  
    }  
    printf("%lld\n",ans);  
}  
int main()  
{  
    //注意GCJ需要提交输出文件，正式比赛还需要提交源代码  
    freopen("A-large-practice.in","r",stdin);  
    freopen("A-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        for(int i=0;i<n;i++){  
            scanf("%d",&v1[i]);  
        }  
        for(int i=0;i<n;i++){  
            scanf("%d",&v2[i]);  
        }  
        printf("Case #%d: ",++kase);  
        solve();  
    }  
    return 0;  
}  
