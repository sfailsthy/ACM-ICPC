//created by sfailsthy 2016/12/21 23:55
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn =15;
typedef long long LL;

int degree[maxn];
LL C[maxn][maxn];

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

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        memset(degree,0,sizeof(degree));
        memset(C,0,sizeof(C));
        scanf("%d%d",&n,&m);
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            C[u][v]=C[v][u]=-1;
            degree[v]++;
            degree[u]++;
        }

        for(int i=0;i<n;i++){
            C[i][i]=degree[i];
        }
        printf("%lld\n",det(C,n));
    }
    return 0;
}
