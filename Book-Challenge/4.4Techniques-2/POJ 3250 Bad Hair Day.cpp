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
const int maxn=1005;  
  
typedef long long ll;  
int main()  
{  
    int n,h,t;  
    ll sum=0;  
    scanf("%d",&n);  
    stack<int> s;  
    scanf("%d",&h);  
    s.push(h);  
    for(int i=1;i<n;i++){  
        scanf("%d",&t);  
        while(!s.empty()&&t>=s.top()){  
            s.pop();  
        }  
        sum+=s.size();  
        s.push(t);  
    }  
    printf("%lld\n",sum);  
    return 0;  
}  
