#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const int maxn =20;
int n;
int s[maxn];

int main(){
    int kase=0;
    while(scanf("%d",&n)!=EOF&&n){
       for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
       }
       LL res=-INF;
       for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                LL ans=1;
                for(int k=i;k<=j;k++){
                    ans*=s[k];
                }
                res=max(res,ans);
            }
       }
       if(res<0) res=0;
       printf("Case #%d: The maximum product is %lld.\n\n",++kase,res);
    }
    return 0;
}
