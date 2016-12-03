//created by sfailsthy 2016/12/3 22:25
#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

const int maxn =100+10;
int n,m;
int a[maxn];

void solve(){
    queue<pair<int,int> > que;
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        que.push(make_pair(a[i],i));
        pq.push(a[i]);
    }

    int cnt=0;
    for(;;){
        pair<int,int> first=que.front();
        int index=first.second;
        int val=first.first;

        if(val<pq.top()){
            que.pop();
            que.push(first);
        }
        else{
            que.pop();
            pq.pop();
            cnt++;
            if(index==m){
                printf("%d\n",cnt);
                return;
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&n,&m);
       for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
       }
       solve();
    }
    return 0;
}
