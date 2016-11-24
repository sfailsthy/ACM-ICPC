//created by sfailsthy 2016/11/24 21:35
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const int maxn=45000+10;
LL A[maxn],B[maxn];
int n,M;

LL mod_pow(LL x,LL n,LL mod){
    LL res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

void solve(){
    LL res=0;
    for(int i=0;i<n;i++){
        res+=mod_pow(A[i],B[i],M);
        res=res%M;
    }
    cout<<res<<endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>M>>n;
        for(int i=0;i<n;i++){
            cin>>A[i]>>B[i];
        }
        solve();
    }
    return 0;
}
