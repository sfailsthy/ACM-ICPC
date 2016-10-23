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
#include<stack>  
#include<sstream>  
using namespace std;  
#define INF 0x7fffffff  
#define maxn 1005  
  
int n;  
int A[maxn][maxn];  
  
struct Item  
{  
    int s,b;//s=A[a]+B[b];  
    Item(int s,int b):s(s),b(b){}  
    bool operator < (const Item& rhs) const{  
        return s>rhs.s;  
    }  
};  
  
//假设A和B的元素已经从小到大排好序  
//数组C中存放n^2个和中最小的n个和  
void merge(int *A,int *B,int *C,int n)  
{  
    priority_queue<Item> que;  
    for(int i=0;i<n;i++){  
        que.push(Item(A[i]+B[0],0));  
    }  
    for(int i=0;i<n;i++){  
        Item item=que.top();  
        que.pop();  
        C[i]=item.s;  
        int b=item.b;  
        if(b+1<n) que.push(Item(item.s-B[b]+B[b+1],b+1));  
        //加入A[a]+B[b+1]=s-B[b]+B[b+1]  
    }  
}  
  
void solve()  
{  
    for(int i=0;i<n;i++){  
        sort(A[i],A[i]+n);  
    }  
    for(int i=1;i<n;i++){  
        merge(A[0],A[i],A[0],n);  
    }  
    for(int i=0;i<n-1;i++){  
        printf("%d ",A[0][i]);  
    }  
    printf("%d\n",A[0][n-1]);  
}  
  
int main()  
{  
    while(scanf("%d",&n)!=EOF){  
        for(int i=0;i<n;i++){  
            for(int j=0;j<n;j++){  
                scanf("%d",&A[i][j]);  
            }  
        }  
        solve();  
    }  
    return 0;  
}  
