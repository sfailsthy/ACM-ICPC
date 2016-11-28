//created by sfailsthy 2016/11/25 1:29
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int maxn =65000+100;

int prime[maxn];
bool is_prime[maxn];//is_prime[i]是true表示i是素数
//返回n以内素数的个数
int sieve(int n)  {
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}

LL mod_pow(LL x,LL n,LL mod){
    LL res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

bool check(int n){
    if(is_prime[n]){
        return false;
    }

    for(int x=2;x<n;x++){
        if(mod_pow(x,n,n)!=x){
            return false;
        }
    }

    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int p=sieve(maxn);
    while(cin>>n&&n){
        bool flag=check(n);
        if(flag) cout<<"The number "<<n<<" is a Carmichael number."<<endl;
        else cout<<n<<" is normal."<<endl;
    }
    return 0;
}
