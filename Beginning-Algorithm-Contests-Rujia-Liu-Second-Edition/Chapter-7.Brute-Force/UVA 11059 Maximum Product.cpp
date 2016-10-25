//created by sfailsthy 2016/10/25 22:28
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn =20;
#define INF 0x7fffffff
int s[maxn];
int n;
int main()
{
    int kase=0;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
        }

        long long  res=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long  temp=1;
                for(int k=i;k<=j;k++){
                    temp*=s[k];
                }
                res=max(res,temp);
            }
        }
        if(res<0) res=0;
        printf("Case #%d: The maximum product is %lld.\n",++kase,res);
        printf("\n");
    }
    return 0;
}
