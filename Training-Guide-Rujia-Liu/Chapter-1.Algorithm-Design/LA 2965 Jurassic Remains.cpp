//题目链接:https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=966
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
const int maxn=30;  
map<int,int> table;  
int n;  
int A[maxn];  
char s[1000];  
  
//整数x在二进制表示下有多少位是1  
int bitcount(int x)  
{  
    return x==0?0:bitcount(x/2)+(x&1);  
}  
  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        for(int i=0;i<n;i++){  
            scanf("%s",s);  
            A[i]=0;  
            for(int j=0;s[j]!='\0';j++){  
                A[i]^=(1<<(s[j]-'A'));  
            }  
        }  
  
        //计算前一半元素的所有子集的xor值  
        //table[x]保存的是xor值为x的，bitcount尽量大的值  
        table.clear();  
        int n1=n/2,n2=n-n1;  
        for(int i=0;i<(1<<n1);i++){  
            int x=0;  
            for(int j=0;j<n1;j++){  
                if(i&(1<<j)) x^=A[j];  
            }  
            if(!table.count(x)||bitcount(table[x])<bitcount(i)) table[x]=i;  
        }  
  
        //枚举后n2个元素，并在table中查找  
        int ans=0;  
        for(int i=0;i<(1<<n2);i++){  
            int x=0;  
            for(int j=0;j<n2;j++){  
                if(i&(1<<j)) x^=A[n1+j];  
            }  
            if(table.count(x)&&bitcount(ans)<bitcount(table[x])+bitcount(i))  
                ans=(i<<n1)^table[x];  
        }  
  
        printf("%d\n",bitcount(ans));  
        for(int i=0;i<n;i++){  
            if(ans&(1<<i)) printf("%d ",i+1);  
        }  
        printf("\n");  
    }  
    return 0;  
}  
