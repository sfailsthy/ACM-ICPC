//created by sfailsthy 2016/12/5 1:34
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long LL;

const int maxn =100000+10;
int N,M;
int money[maxn];

bool check(LL x){
    int cnt=1;
    LL expense=0;
    for(int i=0;i<N;i++){
        expense+=money[i];
        if(expense>x){
            expense=money[i];
            cnt++;
        }
    }
    return cnt>M;
}

void solve(){
    LL lb=*max_element(money,money+N),ub=accumulate(money,money+N,0);
    while(ub>lb){
        LL mid=(lb+ub)>>1;
        if(check(mid)){
            lb=mid+1;
        }
        else{
            ub=mid;
        }
    }
    printf("%lld",lb);
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&money[i]);
    }
    solve();
    return 0;
}
