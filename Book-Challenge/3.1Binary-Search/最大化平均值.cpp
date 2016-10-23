/*
有n个物品的重量和价值分别是w[i]和v[i]。从中选出k个物品使得单位重量的价值最大。
数据范围
1<=k<=n<=10^4
1<=w[i],v[i]<=10^6
*/
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
  
int n,k;  
int w[maxn],v[maxn];  
  
double y[maxn];//y=v-x*w;  
  
bool C(double x)  
{  
    for(int i=0;i<n;i++){  
        y[i]=v[i]-x*w[i];  
    }  
    sort(y,y+n);  
  
    //计算数组y中从大到小前k个数的和  
    double sum=0;  
    for(int i=0;i<k;i++){  
        sum+=y[n-i-1];  
    }  
    return sum>=0;  
}  
  
void solve()  
{  
    double lb=0,ub=INF;  
    for(int i=0;i<100;i++){  
        double mid=(lb+ub)/2;  
        if(C(mid)) lb=mid;  
        else ub=mid;  
    }  
    printf("%.2f\n",ub);  
}  
  
int main()  
{  
    scanf("%d%d",&n,&k);  
    for(int i=0;i<n;i++){  
        cin>>w[i]>>v[i];  
    }  
    solve();  
    return 0;  
}  
