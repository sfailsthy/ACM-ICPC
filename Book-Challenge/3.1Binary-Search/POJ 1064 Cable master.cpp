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
  
int N,K;  
double L[maxn];  
  
bool C(double x)  
{  
    int num=0;  
    for(int i=0;i<N;i++){  
        num+=(int)(L[i]/x);  
    }  
    return num>=K;  
}  
  
void solve()  
{  
    double lb=0,ub=INF;  
    for(int i=0;i<100;i++){  
        double mid=(lb+ub)/2;  
        if(C(mid)) lb=mid;  
        else ub=mid;  
    }  
    printf("%.2f\n",floor(ub*100)/100);  
}  
  
int main()  
{  
    scanf("%d%d",&N,&K);  
    for(int i=0;i<N;i++){  
        cin>>L[i];  
    }  
    solve();  
    return 0;  
}  
