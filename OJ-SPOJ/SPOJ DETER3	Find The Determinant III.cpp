//created by sfailsthy 2016/12/22 13:06
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn =200+10;
typedef long long LL;

LL C[maxn][maxn];
int n;
LL Mod;

LL det(LL a[][maxn],int n){
    LL ret=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            while(a[j][i]){
                LL t=a[i][i]/a[j][i];
                for(int k=i;k<n;k++){
                    a[i][k]=(a[i][k]-a[j][k]*t)%Mod;
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
        ret=(ret*a[i][i])%Mod;
    }
    /*if(ret<0){
        ret=-ret;
    }

    return ret%Mod;*/
    return (ret+Mod)%Mod;
}

int main(){
    while(scanf("%d%lld",&n,&Mod)==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&C[i][j]);
            }
        }

        printf("%lld\n",det(C,n));
    }
    return 0;
}
