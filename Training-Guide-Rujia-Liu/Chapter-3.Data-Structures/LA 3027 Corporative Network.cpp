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
#define maxn 20005  
  
//并查集  
int parent[maxn];//父亲节点  
int d[maxn];//到根节点的距离  
  
//函数返回父亲节点  
//路径压缩，同时维护数组d  
int findset(int x)  
{  
    if(parent[x]!=x){  
        int root=findset(parent[x]);  
        d[x]+=d[parent[x]];  
        return parent[x]=root;  
    }  
    else return x;  
}  
  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        int n,u,v;  
        scanf("%d",&n);  
        for(int i=0;i<n;i++){  
            parent[i]=i;  
            d[i]=0;  
        }  
        char c;  
        while(cin>>c&&c!='O'){  
            if(c=='I'){  
                scanf("%d%d",&u,&v);  
                parent[u]=v;  
                d[u]=abs(u-v)%1000;  
            }  
            else if(c=='E'){  
                scanf("%d",&u);  
                findset(u);  
                printf("%d\n",d[u]);  
            }  
        }  
    }  
    return 0;  
}  
