//created by sfailsthy 2016/11/29 13:54
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn =5000+10;
int n;
int dir[maxn];

int f[maxn];
//f[i]表示区间[i,i+K-1]是否翻转

int calc(int K){
    memset(f,0,sizeof(f));
    int res=0;
    int sum=0;//f之和

    for(int i=0;i+K<=n;i++){
        if((dir[i]+sum)%2!=0){
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-K+1>=0){
            sum-=f[i-K+1];
        }
    }

    for(int i=n-K+1;i<n;i++){
        if((dir[i]+sum)%2!=0){
            return -1;
        }

        if(i-K+1>=0){
            sum-=f[i-K+1];
        }
    }

    return res;
}

void solve(){
    int K=1,M=n;
    for(int k=1;k<=n;k++){
        int m=calc(k);
        if(m>=0&&M>m){
            M=m;
            K=k;
        }
    }
    printf("%d %d\n",K,M);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        dir[i]=(c=='F')?0:1;
    }
    solve();
    return 0;
}
