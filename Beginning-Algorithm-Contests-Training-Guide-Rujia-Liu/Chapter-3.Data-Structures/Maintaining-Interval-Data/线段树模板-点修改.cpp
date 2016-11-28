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
#define maxn 100005  
#define maxnode 200005  
  
//线段树的节点编号是1-n  
int ql,qr;//查询[ql,qr]中的最小值  
int p,v;//修改，A[p]=v;  
  
struct IntervalTree  
{  
    int minv[maxnode];  
    //minv[o]表示节点o所对应区间中所有元素的最小值  
  
    //查询[ql,qr]中的最小值  
    int query(int o,int L,int R){  
        int M=L+(R-L)/2;  
        int ans=INF;  
        if(ql<=L&&R<=qr) return minv[o];//当前节点完全包含在查询区间内  
        if(ql<=M) ans=min(ans,query(o*2,L,M));//往左走  
        if(qr>M) ans=min(ans,query(o*2+1,M+1,R));  
        return ans;  
    }  
  
    //修改:A[p]=v;  
    void update(int o,int L,int R){  
        int M=L+(R-L)/2;  
        if(L==R) minv[o]=v;//叶节点直接更新minv  
        else {  
            //L<R  
            //先递归更新左子树或者右子树  
            if(p<=M){  
                update(2*o,L,M);  
            }  
            else{  
                update(2*o+1,M+1,R);  
            }  
  
            //计算本节点的minv  
            minv[0]=min(minv[2*o],minv[2*o+1]);  
        }  
    }  
};  
  
IntervalTree tree;  
  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)==2){  
        memset(&tree,0,sizeof(tree));  
        int op;  
        for(int i=1;i<=n;i++){  
            scanf("%d",&v);  
            p=i;  
            tree.update(1,1,n);//建树的过程  
        }  
        while(m--){  
  
            scanf("%d",&op);  
            if(op==1){  
                scanf("%d%d",&p,&v);  
                tree.update(1,1,n);//修改树节点  
            }  
            else{  
                scanf("%d%d",&ql,&qr);//修改查询区间  
                printf("%d\n",tree.query(1,1,n));  
            }  
        }  
    }  
    return 0;  
}  
