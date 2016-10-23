#include<algorithm>  
#include<cctype>  
#include<cmath>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip>  
#include<iostream>  
#include<map>  
#include<queue>  
#include<string>  
#include<set>  
#include<vector>  
#include<cmath>  
#include<bitset>  
#include<stack>  
#include<sstream>  
#include<deque>  
#include<utility>  
using namespace std;  
#define INF 0x7fffffff  
#define maxn 10005  
  
int prime[maxn];  
bool is_prime[maxn];//is_prime[i]是true表示i是素数  
//返回n以内素数的个数  
int sieve(int n)  
{  
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
  
int n;  
void solve()  
{  
    int p=sieve(n);  
    int s=0,t=0,sum=0;  
    int res=0;  
    for(;;){  
       while(t<p&&sum<n){  
           sum+=prime[t++];  
       }  
       if(sum<n) break;  
       else if(sum==n){  
            res++;  
  
       }  
       sum-=prime[s++];  
    }  
    printf("%d\n",res);  
}  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        solve();  
    }  
    return 0;  
}  
