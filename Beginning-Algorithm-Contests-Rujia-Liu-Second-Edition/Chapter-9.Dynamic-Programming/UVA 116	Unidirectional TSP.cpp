//created by sfailsthy 2016/11/29 1:01
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f

int a[15][105];
int dp[15][105];
int m,n;
int nxt[15][105];

void solve(){
    int ans=INF,first=0;
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<m;i++){
            if(j==n-1) dp[i][j]=a[i][j];
            else{
                int rows[]={i,i-1,i+1};
                if(i==0) rows[1]=m-1;
                if(i==m-1) rows[2]=0;
                sort(rows,rows+3);

                dp[i][j]=INF;

                for(int k=0;k<3;k++){
                    int v=dp[rows[k]][j+1]+a[i][j];
                    if(v<dp[i][j]){
                        dp[i][j]=v;
                        nxt[i][j]=rows[k];
                    }
                }
            }

            if(j==0&&dp[i][j]<ans){
                ans=dp[i][j];
                first=i;
            }
        }

    }

    printf("%d",first+1);

    for(int i=nxt[first][0],j=1;j<n;i=nxt[i][j],j++){
        printf(" %d",i+1);
    }
    printf("\n%d\n",ans);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&m,&n)==2){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        solve();
    }
    return 0;
}
