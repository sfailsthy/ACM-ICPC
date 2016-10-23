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
typedef pair<int,int> P;  
const int maxnode=1<<17;  
int n,m;  
//编号从1到n  
int _min,_max,_sum;//全局变量，目前位置的最小值、最大值以及累加和  
int op,qL,qR,v;  
//m个操作  
//1 L R v  
//2 L R  
struct IntervalTree  
{  
    int sumv[maxnode],minv[maxnode],maxv[maxnode],addv[maxnode];  
  
    //维护信息  
    //维护结点o，它对应的区间是[L,R]  
    void maintain(int o,int L,int R){  
        int lc=2*o,rc=2*o+1;  
        sumv[o]=minv[o]=maxv[o]=0;  
        if(R>L){  
            //考虑左右子树  
            sumv[o]=sumv[lc]+sumv[rc];  
            minv[o]=min(minv[lc],minv[rc]);  
            maxv[o]=max(maxv[lc],maxv[rc]);  
        }  
        //考虑add操作  
        minv[o]+=addv[o];  
        maxv[o]+=addv[o];  
        sumv[o]+=addv[o]*(R-L+1);  
    }  
  
    //修改操作  
    void update(int o,int L,int R){  
        int lc=2*o,rc=2*o+1;  
        if(qL<=L&&R<=qR){  
            //递归边界  
            addv[o]+=v;//累加边界的add值  
        }  
        else{  
           int M=L+(R-L)/2;  
           if(qL<=M) update(lc,L,M);  
           if(qR>M) update(rc,M+1,R);  
        }  
        //递归结束前重新计算本结点的附加信息  
        maintain(o,L,R);  
    }  
  
    void query(int o,int L,int R,int add){  
        if(qL<=L&&R<=qR){  
            //递归边界:用边界区间的附加信息更新答案  
            _sum+=sumv[o]+add*(R-L+1);  
            _min=min(_min,minv[o]+add);  
            _max=max(_max,maxv[o]+add);  
        }  
        else{  
            //不递归统计，累加参数add  
            int M=L+(R-L)/2;  
            if(qL<=M) query(2*o,L,M,add+addv[o]);  
            if(qR>M) query(2*o+1,M+1,R,add+addv[o]);  
        }  
    }  
};  
  
IntervalTree tree;  
  
int main()  
{  
    while(scanf("%d%d",&n,&m)==2){  
        memset(&tree,0,sizeof(tree));  
        while(m--){  
            scanf("%d%d%d",&op,&qL,&qR);  
            if(op==1){  
                scanf("%d",&v);  
                tree.update(1,1,n);  
            }  
            else{  
                _sum=0,_min=INF,_max=-INF;  
                tree.query(1,1,n,0);  
                printf("%d %d %d\n",_sum,_min,_max);  
            }  
        }  
    }  
    return 0;  
}  
