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
using namespace std;  
#define INF 0x7fffffff  
const int maxn=100005;  
  
typedef long long ll;  
  
int n;  
int h[maxn];  
int L[maxn],R[maxn];  
  
void solve()  
{  
    //计算L  
    stack<int> s;  
    for(int i=0;i<n;i++){  
        while(!s.empty()&&h[s.top()]>=h[i]){  
            s.pop();  
        }  
        L[i]=(s.empty())?0:(s.top()+1);  
        s.push(i);  
    }  
  
    while(!s.empty()){  
        s.pop();  
    }  
  
    //计算R  
    for(int i=n-1;i>=0;i--){  
        while(!s.empty()&&h[s.top()]>=h[i]){  
            s.pop();  
        }  
        R[i]=(s.empty())?n:s.top();  
        s.push(i);  
    }  
  
    ll res=0;  
    for(int i=0;i<n;i++){  
        res=max(res,(ll)h[i]*(R[i]-L[i]));  
    }  
  
    printf("%lld\n",res);  
}  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        for(int i=0;i<n;i++){  
            scanf("%d",&h[i]);  
        }  
        solve();  
    }  
    return 0;  
}  
