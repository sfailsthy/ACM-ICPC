/*#include <algorithm> 
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
using namespace std;*/  
#include<bits/stdc++.h>//这个包含所有的头文件  
using namespace std;  
#define INF 0x7fffffff  
  
struct Job  
{  
    int j,b;  
    bool operator < (const Job& x) const{  
        return j>x.j;  
    }  
};  
  
int main()  
{  
    int kase=1;  
    int n,b,j;  
    while(scanf("%d",&n)!=EOF&&n){  
        vector<Job> vec;  
        for(int i=0;i<n;i++){  
            scanf("%d%d",&b,&j);  
            vec.push_back((Job){j,b});  
        }  
        sort(vec.begin(),vec.end());  
        int s=0;  
        int ans=0;  
        for(int i=0;i<n;i++){  
            s+=vec[i].b;//当前任务开始的执行时间  
            ans=max(ans,s+vec[i].j);//更新任务执行完毕的最晚时间  
        }  
        printf("Case %d: %d\n",kase++,ans);  
    }  
    return 0;  
}  
