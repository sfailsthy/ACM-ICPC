//created by sfailsthy 2016/12/6
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x7fffffff
const int maxnode=(1<<18)-1;
typedef long long LL;

int n,m;
//编号从1到n
LL _min,_max,_sum;//全局变量，目前位置的最小值，最大值及累加和
int qL,qR,v;
char op;
//m个操作
//1 L R v
//2 L R

struct IntervalTree{
    LL sumv[maxnode],minv[maxnode],maxv[maxnode],addv[maxnode];
    //sumv[o]表示如果只执行结点o及其子孙结点中的add操作，结点o对应区间的所有数之和

    //维护信息
    //维护结点o，其对应区间[L,R];
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

    //参数add表示当前区间的所有祖先结点的add值之和
    void query(int o,int L,int R,LL add){
        if(qL<=L&&R<=qR){
            //递归边界:用边界区间的附加信息更新答案
            _sum+=sumv[o]+add*(R-L+1);
            _min=min(_min,minv[o]+add);
            _max=max(_max,maxv[o]+add);
        }
        else{
            //递归统计，累加参数add
            int M=L+(R-L)/2;
            if(qL<=M) query(2*o,L,M,add+addv[o]);
            if(qR>M) query(2*o+1,M+1,R,add+addv[o]);
        }
    }
};

IntervalTree tree;

int main(){
    while(scanf("%d%d",&n,&m)==2){
        memset(&tree,0,sizeof(tree));
        for(int i=0;i<n;i++){
            qL=qR=i+1;
            scanf("%d",&v);
            tree.update(1,1,n);
        }

        for(int i=0;i<m;i++){
            scanf("%d%d",&qL,&qR);
            _sum=0,_min=INF,_max=-INF;
            tree.query(1,1,n,0);
            printf("%lld\n",_max-_min);
        }
    }
    return 0;
}
