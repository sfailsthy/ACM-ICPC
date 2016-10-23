//题目链接:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925
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
#include<stack>  
using namespace std;  
#define INF 0x7fffffff  
typedef long long ll;  
const int maxn=(1<<16)+10;  
//用cover[S]表示若干P[i]的集合S中所有P[i]的并集。  
//用f(S)表示子集S最多可以分多少组  
int P[maxn],cover[maxn],f[maxn];  
int n,m;  
  
int main()  
{  
    int kase=0;  
    while(scanf("%d",&n)!=EOF&&n){  
        for(int i=0;i<n;i++){  
            scanf("%d",&m);  
            P[i]=1<<i;  
            while(m--){  
                int x;  
                scanf("%d",&x);  
                P[i]|=(1<<x);  
            }  
        }  
  
        for(int S=0;S<(1<<n);S++){  
            cover[S]=0;  
            for(int i=0;i<n;i++){  
                if(S&(1<<i)){  
                    cover[S]|=P[i];  
                }  
            }  
        }  
  
        f[0]=0;  
        int All=(1<<n)-1;  
        for(int S=1;S<(1<<n);S++){  
            f[S]=0;  
            //枚举集合S的所有子集  
            for(int S0=S;S0;S0=(S0-1)&S){  
                if(cover[S0]==All){  
                    f[S]=max(f[S],f[S^S0]+1);  
                }  
            }  
        }  
  
        printf("Case %d: %d\n",++kase,f[All]);  
    }  
    return 0;  
}  
