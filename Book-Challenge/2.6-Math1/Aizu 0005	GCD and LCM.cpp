//created by sfailsthy 2016/11/24 21:33
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    return (b==0)?a:gcd(b,a%b);
}

LL lcm(LL a,LL b){
    return a*b/gcd(a,b);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL a,b;
    while(scanf("%lld%lld",&a,&b)==2){
        printf("%lld ",gcd(a,b));
        printf("%lld\n",lcm(a,b));
    }
    return 0;
}
