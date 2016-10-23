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
#define maxn 10005  
  
map<int,vector<int> >a;  
int main()  
{  
    int n,m,k,v;  
    while(scanf("%d%d",&n,&m)==2){  
        for(int i=0;i<n;i++){  
            int x;  
            scanf("%d",&x);  
            if(!a.count(x)){  
                a[x]=vector<int>();  
            }  
            a[x].push_back(i+1);  
        }  
        while(m--){  
            scanf("%d%d",&k,&v);  
            if(!a.count(v)||a[v].size()<k){  
                printf("0\n");  
            }  
            else printf("%d\n",a[v][k-1]);  
        }  
    }  
    return 0;  
}  
