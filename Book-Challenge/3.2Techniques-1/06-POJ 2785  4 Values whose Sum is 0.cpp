#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn =4000+10;
int n;
int A[maxn],B[maxn],C[maxn],D[maxn];
int AB[maxn*maxn];

void solve(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            AB[i*n+j]=A[i]+B[j];
        }
    }

    sort(AB,AB+n*n);
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ab=-(C[i]+D[j]);
            res+=upper_bound(AB,AB+n*n,ab)-lower_bound(AB,AB+n*n,ab);
        }
    }
    printf("%lld\n",res);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    }
    solve();
    return 0;
}
