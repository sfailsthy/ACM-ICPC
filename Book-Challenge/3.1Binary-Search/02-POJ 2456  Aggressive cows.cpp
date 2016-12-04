#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =100000+10;
int N,C;
int x[maxn];

bool check(int d){
    int last=0;
    for(int i=1;i<C;i++){
        int cnt=last+1;
        while(cnt<N&&x[cnt]-x[last]<d){
            cnt++;
        }
        if(cnt==N) return false;
        last=cnt;
    }
    return true;
}

void solve(){
    sort(x,x+N);
    int lb=0,ub=INF;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(check(mid)){
            lb=mid;
        }
        else{
            ub=mid;
        }
    }
    printf("%d\n",lb);
}

int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>x[i];
    }
    solve();
    return 0;
}
