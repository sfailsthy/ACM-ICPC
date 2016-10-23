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
#define maxn 200005  
  
int n,m;  
int father[maxn];  
int sum[maxn],num[maxn];  
  
void init()  
{  
    for(int i=1;i<=n;i++){  
        father[i]=i+n;  
        father[i+n]=i+n;  
        sum[i+n]=i;  
        num[i+n]=1;  
    }  
}  
  
int Find(int x)  
{  
    if(x!=father[x]){  
        father[x]=Find(father[x]);  
    }  
    return father[x];  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m)!=EOF){  
        init();  
        int mark,p,q;  
        for(int i=0;i<m;i++){  
            scanf("%d",&mark);  
            if(mark==1){  
                scanf("%d%d",&p,&q);  
                int fatherP=Find(p);  
                int fatherQ=Find(q);  
                if(fatherP!=fatherQ){  
                    father[fatherP]=fatherQ;  
                    sum[fatherQ]+=sum[fatherP];  
                    num[fatherQ]+=num[fatherP];  
                }  
            }  
            else if(mark==2){  
                scanf("%d%d",&p,&q);  
                int fatherP=Find(p);  
                int fatherQ=Find(q);  
                if(fatherP!=fatherQ){  
                    father[p]=fatherQ;  
                    sum[fatherQ]+=p;  
                    sum[fatherP]-=p;  
                    num[fatherP]--;  
                    num[fatherQ]++;  
                }  
            }  
            else{  
                scanf("%d",&p);  
                int fatherP=Find(p);  
                printf("%d %d\n",num[fatherP],sum[fatherP]);  
            }  
        }  
    }  
    return 0;  
}  
