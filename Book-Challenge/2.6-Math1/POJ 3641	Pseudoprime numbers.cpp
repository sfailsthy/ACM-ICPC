//created by sfailsthy 2016/11/25 12:20
/*
伪素数：满足①p不是素数②存在a > 1使得ap = a (mod p)的p是伪素数，给出p和a，判断p是否是伪素数。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }

    return n!=1;
}

LL mod_pow(LL x,LL n,LL mod){
    LL res=1;
    while(n>0){
        if(n&1){
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main(){
    int p,a;
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin>>p>>a){
        if(p==0&&a==0) break;
        if(!is_prime(p)&&(mod_pow(a,p,p)==a)){
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}
