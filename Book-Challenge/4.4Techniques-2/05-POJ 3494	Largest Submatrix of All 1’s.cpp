//created by sfailsthy 2016/12/12 20:50
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int,int> P;

const int maxn =2000+10;
int m,n;
int a[maxn][maxn];
int u[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn];

void solve(){
    memset(u,0,sizeof(u));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                u[i][j]=0;
            }
            else{
                u[i][j]=u[i-1][j]+1;
            }
        }
    }

    stack<P> s;
    for(int i=1;i<=m;i++){
        while(!s.empty()) s.pop();
        for(int j=1;j<=n;j++){
            while(!s.empty()&&s.top().first>=u[i][j]){
                s.pop();
            }
            l[i][j]=(s.empty())?1:(s.top().second+1);
            s.push(P(u[i][j],j));
        }
    }

    for(int i=1;i<=m;i++){
        while(!s.empty()) s.pop();
        for(int j=n;j>=1;j--){
            while(!s.empty()&&s.top().first>=u[i][j]){
                s.pop();
            }
            r[i][j]=(s.empty())?(m+1):s.top().second;
            s.push(P(u[i][j],j));
        }
    }

    int res=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            res=max(res,u[i][j]*(r[i][j]-l[i][j]));
        }
    }
    printf("%d\n",res);
}

int main(){
    while(scanf("%d%d",&m,&n)==2){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        solve();
    }
    return 0;
}
