//created by sfailsthy 2016/11/23 20:08
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long LL;

const int maxn =2e5+10;
int N;
int L[maxn];

void solve(){
    priority_queue<int,vector<int>,greater<int> > que;
    for(int i=0;i<N;i++){
        que.push(L[i]);
    }

    LL ans=0;
    while(que.size()>1){
        int L1,L2;
        L1=que.top();
        que.pop();
        L2=que.top();
        que.pop();

        ans+=L1+L2;
        que.push(L1+L2);
    }
    printf("%lld\n",ans);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&L[i]);
    }
    solve();
    return 0;
}
