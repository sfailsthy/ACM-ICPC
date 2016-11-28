//created by sfailsthy 2016/11/29 1:34
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn =10000+10;
bool is_prime[maxn];
int primes[maxn];

int sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;

    int p=0;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            primes[p++]=i;
            for(int j=2*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }

    return p;
}

void solve(int n){
    int p=sieve(n);
    int s=0,t=0,res=0,sum=0;
    for(;;){
        while(t<p&&sum<n){
            sum+=primes[t++];
        }

        if(sum<n){
            break;
        }
        else if(sum==n){
            res++;
        }
        sum-=primes[s++];
    }

    printf("%d\n",res);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        solve(n);
    }
    return 0;
}
