//created by sfailsthy 2016/12/5 13:25
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
const int maxm=5000+10;

int N,M;
int A[maxn];
int I[maxm],J[maxm],K[maxm];
int nums[maxn];
vector<int> data[(1<<18)-1];

//构建线段树
//k是结点的编号，与区间[l,r)对应
void init(int k,int l,int r){
    if(r-l==1){
        data[k].push_back(A[l]);
    }
    else{
        int lch=2*k+1,rch=2*k+2;
        init(lch,l,(l+r)/2);
        init(rch,(l+r)/2,r);
        data[k].resize(r-l);
        merge(data[lch].begin(),data[lch].end(),data[rch].begin(),data[rch].end(),data[k].begin());
    }
}

//计算[i,j)中不超过x的数的个数
//k是结点的编号，和区间[l,r)对应
int query(int i,int j,int x,int k,int l,int r){
    if(j<=l||r<=i){
        return 0;
    }
    else if(i<=l&&r<=j){
        return upper_bound(data[k].begin(),data[k].end(),x)-data[k].begin();
    }

    else{
        int lc=query(i,j,x,2*k+1,l,(l+r)/2);
        int rc=query(i,j,x,2*k+2,(l+r)/2,r);
        return lc+rc;
    }
}

void solve(){
    for(int i=0;i<N;i++){
        nums[i]=A[i];
    }
    sort(nums,nums+N);

    init(0,0,N);

    for(int i=0;i<M;i++){
        int l=I[i],r=J[i]+1,k=K[i];

        int lb=-1,ub=N-1;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            int c=query(l,r,nums[mid],0,0,N);
            if(c>=k) ub=mid;
            else lb=mid;
        }
        printf("%d\n",nums[ub]);
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&I[i],&J[i],&K[i]);
        I[i]--;
        J[i]--;
    }
    solve();
    return 0;
}
