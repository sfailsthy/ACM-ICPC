#include <algorithm>   
#include <cctype>   
#include <cmath>   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
#include <iomanip>   
#include <iostream>   
#include <map>   
#include <queue>   
#include <string>   
#include <set>   
#include <vector>   
#include<cmath>   
#include<bitset>   
#include<sstream>   
using namespace std;  
using namespace std;  
#define INF 0x7fffffff  
typedef long long ll;  
const int maxn=1e6+10;  
ll A[maxn],C[maxn],tot,M;  
int n;  
  
int main()  
{  
    while(scanf("%lld",&n)!=EOF){  
        tot=0;  
        for(int i=0;i<n;i++){  
            scanf("%lld",&A[i]);  
            tot+=A[i];  
        }  
        M=tot/n;  
        C[0]=0;  
        for(int i=1;i<n;i++){  
            C[i]=C[i-1]+A[i]-M;  
        }  
        sort(C,C+n);  
        ll x1=C[n/2],ans=0;  
        for(int i=0;i<n;i++){  
            ans+=fabs(C[i]-x1);  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  
