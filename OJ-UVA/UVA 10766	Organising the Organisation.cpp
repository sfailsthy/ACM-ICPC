//created by sfailsthy 2016/12/22 1:05
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn =50+10;
typedef long long LL;

int degree[maxn];
bool G[maxn][maxn];
LL C[maxn][maxn];
int n,m,k;

LL det(LL a[][maxn],int n){
    LL ret=1;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            while(a[j][i]){
                LL t=a[i][i]/a[j][i];
                for(int k=i;k<n;k++){
                    a[i][k]=a[i][k]-a[j][k]*t;
                }

                for(int k=i;k<n;k++){
                    swap(a[i][k],a[j][k]);
                }

                ret=-ret;
            }
        }

        if(a[i][i]==0){
            return 0;
        }
        ret=ret*a[i][i];
    }
    if(ret<0){
        ret=-ret;
    }
    return ret;
}

void solve(){
   memset(degree,0,sizeof(degree));
   memset(C,0,sizeof(C));

   for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(G[i][j]){
                C[i][j]=C[j][i]=-1;
                degree[i]++;
                degree[j]++;
            }
            
        }
   } 

   for(int i=0;i<n;i++){
        C[i][i]=degree[i];
   }
   printf("%lld\n",det(C,n));
}

int main(){
    while(scanf("%d%d%d",&n,&m,&k)==3){
        memset(G,true,sizeof(G));
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u][v]=G[v][u]=false;
        }
        solve();
    }
    return 0;
}
