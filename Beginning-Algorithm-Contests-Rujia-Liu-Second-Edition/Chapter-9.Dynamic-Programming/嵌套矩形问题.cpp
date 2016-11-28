//created by sfailsthy 2016/11/28 23:36
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn =1000+10;
int n;
int a[maxn],b[maxn];
int G[maxn][maxn];
int d[maxn];

int dp(int i){
    int& ans=d[i];

    if(ans>0) return ans;
    ans=1;
    for(int j=0;j<n;j++){
        if(G[i][j]){
            ans=max(ans,dp(j)+1);
        }
    }
    return ans;
}

void print_ans(int i){
    printf("%d ",i+1);

    for(int j=0;j<n;j++){
        if(G[i][j]==1&&d[i]==d[j]+1){
            print_ans(j+1);
            break;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            if(a[i]>b[i]){
                swap(a[i],b[i]);
            }
        }

        memset(G,0,sizeof(G));
        memset(d,0,sizeof(d));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]<a[j]&&b[i]<b[j]){
                    G[i][j]=1;
                }
            }
        }

        int res=0,ans=0;
        for(int i=0;i<n;i++){
            if(dp(i)>res){
                res=dp(i);
                ans=i;
            }
        }
        printf("%d\n",res);
        print_ans(ans);
    }
    return 0;
}
