//created by sfailsthy 2016/11/28 15:22
//时间复杂度为O(2^n)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn =100+10;
int n,W;
int w[maxn],v[maxn];

//从第i个物品开始选总重小于j的部分
int rec(int i,int j){
    int res;
    if(i==n){
        res=0;
    }

    else if(j<w[i]){
        res=rec(i+1,j);
    }

    else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }

    return res;
}

int main(){
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    printf("%d\n",rec(0,W));
    return 0;
}
