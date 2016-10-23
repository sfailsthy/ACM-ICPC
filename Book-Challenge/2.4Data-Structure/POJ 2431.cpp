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
  
//A[i]表示起点到各个加油站的距离  
//B[i]表示各个加油站的可以给卡车加的汽油量  
//C[i]表示各个加油站到终点的距离  
int L,P,N;  
int A[maxn],B[maxn],C[maxn];  
pair<int,int> pir[maxn];  
void solve()  
{  
    //为了写起来方便，我们把终点也认为是加油站  
    A[N]=L;  
    B[N]=0;  
    N++;  
  
    //维护加油站的优先队列  
    priority_queue<int> que;  
  
    //ans:加油次数，pos:现在所在位置，tank:油箱中汽油的量  
    int ans=0,pos=0,tank=P;  
    for(int i=0;i<N;i++){  
        //接下来要行驶的距离  
        int d=A[i]-pos;  
        //不断加油直至油量足够行驶到下一个加油站  
        while(tank-d<0){  
            if(que.empty()){  
                cout<<-1<<endl;  
                return;  
            }  
            tank+=que.top();  
            que.pop();  
            ans++;  
        }  
        tank-=d;  
        pos=A[i];  
        que.push(B[i]);  
    }  
    printf("%d\n",ans);  
}  
  
int main()  
{  
    scanf("%d",&N);  
    for(int i=0;i<N;i++){  
        scanf("%d%d",&C[i],&B[i]);  
    }  
    scanf("%d%d",&L,&P);  
    for(int i=0;i<N;i++){  
        A[i]=L-C[i];  
    }  
    for(int i=0;i<N;i++){  
        pir[i]=make_pair(A[i],B[i]);  
    }  
    //按照A[i]从小到大的顺序排序  
    sort(pir,pir+N);  
    for(int i=0;i<N;i++){  
        A[i]=pir[i].first;  
        B[i]=pir[i].second;  
    }  
    solve();  
    return 0;  
}  
