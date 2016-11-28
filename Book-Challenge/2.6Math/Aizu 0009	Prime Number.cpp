//created by sfailsthy 2016/11/24 21:34
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const int maxn=1e7+10;
int prime[maxn];
bool is_prime[maxn];

int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return p;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",sieve(n));
    }
    return 0;
}
