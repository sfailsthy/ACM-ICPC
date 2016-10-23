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
#include<stack>  
using namespace std;  
#define INF 0x7fffffff  
typedef long long ll;  
const int maxnode=1<<17;  
  
int _sum,_min,_max,op,qL,qR,v;  
struct IntervalTree  
{  
    int sumv[maxnode],maxv[maxnode],minv[maxnode],setv[maxnode];  
  
    //维护信息  
    void maintain(int o,int L,int R){  
        int lc=2*o,rc=2*o+1;  
        if(R>L){  
            sumv[o]=sumv[lc]+sumv[rc];  
            minv[o]=min(minv[lc],minv[rc]);  
            maxv[o]=max(maxv[lc],maxv[rc]);  
        }  
        if(setv[o]>=0){  
            minv[o]=maxv[o]=setv[o];  
            sumv[o]=setv[o]*(R-L+1);  
        }  
    }  
  
    //标记传递  
    void pushdown(int o){  
        int lc=2*o,rc=2*o+1;  
        if(setv[o]>=0){  
            //本结点有标记才传递。注意本题中set值非负  
            setv[lc]=setv[rc]=setv[o];  
            setv[o]=-1;//清除本结点标记  
        }  
    }  
  
    //更新信息  
    void update(int o,int L,int R){  
        int lc=2*o,rc=2*o+1;  
        if(qL<=L&&R<=qR){  
            //标记修改  
            setv[o]=v;  
        }  
        else{  
            pushdown(o);  
            int M=L+(R-L)/2;  
            if(qL<=M) update(lc,L,M); else maintain(lc,L,M);  
            if(qR>M) update(rc,M+1,R); else maintain(rc,M+1,R);  
        }  
        maintain(o,L,R);  
    }  
  
    void query(int o,int L,int R){  
        if(setv[o]>=0){  
            //递归边界1:有set标记  
            _sum+=setv[o]*(min(R,qR)-max(L,qL)+1);  
            _min=min(_min,setv[o]);  
            _max=max(_max,setv[o]);  
        }  
        else if(qL<=L&&qR>=R){  
            //递归边界2:边界区间  
            //此边界区间没有被任何set操作影响  
            _sum+=sumv[o];  
            _min=min(_min,minv[o]);  
            _max=max(_max,maxv[o]);  
        }  
        else{  
            //递归统计  
            int M=L+(R-L)/2;  
            if(qL<=M) query(2*o,L,M);  
            if(qR>M) query(2*o+1,M+1,R);  
        }  
    }  
};  
  
IntervalTree tree;  
  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)==2){  
        memset(&tree,0,sizeof(tree));  
        memset(tree.setv,-1,sizeof(tree.setv));  
        tree.setv[1]=0;  
        while(m--){  
            scanf("%d%d%d",&op,&qL,&qR);  
            if(op==1){  
                scanf("%d",&v);  
                tree.update(1,1,n);  
            }  
            else{  
                _sum=0;_min=INF;_max=-INF;  
                tree.query(1,1,n);  
                printf("%d %d %d\n",_sum,_min,_max);  
            }  
        }  
    }  
    return 0;  
}  
