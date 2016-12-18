//created by sfailsthy 2016/12/18 11:09
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =50000+10;
const int maxm =500000+10;
//存储线段树的全局数组
int n,m,data[(1<<17)-1];
int s[maxm],t[maxm];
int dp[maxn];
//下标从0开始

void init(int N){
    n=1;
    while(n<N){
        n=n<<1;
    }
    for(int i=0;i<2*n-1;i++){
        data[i]=INF;
    }
}

void update(int k,int a){
    k+=n-1;
    data[k]=a;
    while(k>0){
        k=(k-1)>>1;
        data[k]=min(data[2*k+1],data[2*k+2]);
    }
}

//求[a,b)的最小值
//外部调用时，用query(a,b,0,0,n)
int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return INF;
    if(a<=l&&r<=b) return data[k];
    else{
        int vl=query(a,b,2*k+1,l,(l+r)>>1);
        int vr=query(a,b,2*k+2,(l+r)>>1,r);
        return min(vl,vr);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&s[i],&t[i]);
    }
    int x=n;
    init(n);
    fill(dp,dp+x+1,INF);
    dp[1]=0;
    update(0,0);

    for(int i=0;i<m;i++){
        int v=min(dp[t[i]],query(s[i]-1,t[i],0,0,n)+1);
        dp[t[i]]=v;
        update(t[i]-1,v);
    }
    printf("%d\n",dp[x]);
    return 0;
}
