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
  
int par[maxn];//父亲  
int Rank[maxn];//树的高度  
//初始化  
void init(int n)  
{  
    for(int i=0;i<n;i++){  
        par[i]=-1;  
        Rank[i]=0;  
    }  
}  
//查询父亲，路径压缩  
int Find(int x)  
{  
    int s;  
    for(s=x;par[s]!=-1;s=par[s]);  
    while(s!=x){  
        int temp=par[x];  
        par[x]=s;  
        x=temp;  
    }  
    return s;  
}  
//合并x，y属于的集合  
void unite(int x,int y)  
{  
    x=Find(x);y=Find(y);  
    if(x==y) return;  
    if(Rank[x]<Rank[y]){  
        par[x]=y;  
    }  
    else{  
        par[y]=x;  
        if(Rank[x]==Rank[y]) Rank[x]++;  
    }  
}  
bool same(int x,int y)  
{  
    return Find(x)==Find(y);  
}  
  
int main()  
{  
    int x,y;  
    while(scanf("%d",&x)==1){  
        init(maxn);  
        int res=0;  
        while(x!=-1){  
            scanf("%d",&y);  
            if(same(x,y)) res++;  
            else unite(x,y);  
            scanf("%d",&x);  
        }  
        printf("%d\n",res);  
    }  
    return 0;  
}  
