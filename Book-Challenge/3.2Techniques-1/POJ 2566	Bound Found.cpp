//created by sfailsthy 2016/11/30 2:54
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
typedef pair<int,int> P;
const int maxn =1e5+10;

int n,k;
int t;
int a[maxn];
P pre[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&k)==2&&n&&k){
        pre[0].first=0;
        pre[0].second=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pre[i].first=pre[i-1].first+a[i];
            pre[i].second=i;
        }
        sort(pre,pre+n+1);

        for(int i=0;i<k;i++){
            scanf("%d",&t);
            int ansl,ansr;
            int ans,diff=INF;
            int l=0,r=1;
            while(r<=n){
                int sub=pre[r].first-pre[l].first;
                if(abs(sub-t)<diff){
                    diff=abs(sub-t);
                    ansl=min(pre[r].second,pre[l].second)+1;
                    ansr=max(pre[l].second,pre[r].second);
                    ans=sub;
                }

                if(sub<t) r++;
                else if(sub>t) l++;
                else break;

                if(l==r) r++;
            }

            printf("%d %d %d\n",ans,ansl,ansr);
        }
    }
    return 0;
}
