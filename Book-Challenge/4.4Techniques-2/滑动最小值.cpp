#include<algorithm>  
#include<cctype>  
#include<cmath>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip>  
#include<iostream>  
#include<map>  
#include<queue>  
#include<string>  
#include<set>  
#include<vector>  
#include<cmath>  
#include<bitset>  
#include<stack>  
#include<sstream>  
#include<deque>  
using namespace std;  
  
const int maxn=1e6+5;  
int n,k;  
int a[maxn],b[maxn];  
  
void solve()  
{  
    deque<int> deq;  
    //双端队列是递增的  
    for(int i=0;i<n;i++){  
        //在双端队列末尾加入i  
        while(!deq.empty()&&a[deq.back()]>=a[i]){  
            deq.pop_back();  
        }  
        deq.push_back(i);  
  
        if(i-k+1>=0){  
            b[i-k+1]=a[deq.front()];  
            if(deq.front()==i-k+1){  
                //从双端队列的队头删除元素  
                deq.pop_front();  
            }  
        }  
    }  
    for(int i=0;i<n-k;i++){  
        cout<<b[i]<<" ";  
    }  
    cout<<b[n-k]<<endl;  
}  
int main()  
{  
    scanf("%d%d",&n,&k);  
    for(int i=0;i<n;i++){  
        scanf("%d",&a[i]);  
    }  
    solve();  
    return 0;  
}  
