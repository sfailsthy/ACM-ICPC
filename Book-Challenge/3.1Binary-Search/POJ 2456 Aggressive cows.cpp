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
#define INF 0x7fffffff  
#define maxn 100005  
  
int N,M;  
int x[maxn];  
  
bool C(int d)  
{  
    int last=0;  
    for(int i=1;i<M;i++){  
        int crt=last+1;  
        while(crt<N&&x[crt]-x[last]<d){  
            crt++;  
        }  
        if(crt==N) return false;  
        last=crt;  
    }  
    return true;  
}  
  
void solve()  
{  
    sort(x,x+N);  
    int lb=0,ub=INF;  
    while(ub-lb>1){  
        int mid=(lb+ub)/2;  
        if(C(mid)) lb=mid;  
        else ub=mid;  
    }  
    printf("%d\n",lb);  
}  
  
int main()  
{  
    scanf("%d%d",&N,&M);  
    for(int i=0;i<N;i++){  
        cin>>x[i];  
    }  
    solve();  
    return 0;  
}  
