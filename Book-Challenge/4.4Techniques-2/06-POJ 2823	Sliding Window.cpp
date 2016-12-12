//created by sfailsthy 2016/12/12 19:34
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
const int maxn =1e6+10;
int n,k;
int a[maxn];
int b[maxn];

void solve(){
    deque<int> deq;
    for(int i=0;i<n;i++){
        while(!deq.empty()&&a[deq.back()]>=a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(i-k+1>=0){
            b[i-k+1]=a[deq.front()];
            if(i-k+1==deq.front()){
                deq.pop_front();
            }
        }
    }
    for(int i=0;i<=n-k;i++){
        printf("%d%c",b[i],i==n-k?'\n':' ');
    }

    while(!deq.empty()){
        deq.pop_back();
    }
    for(int i=0;i<n;i++){
        while(!deq.empty()&&a[deq.back()]<=a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(i-k+1>=0){
            b[i-k+1]=a[deq.front()];
            if(i-k+1==deq.front()){
                deq.pop_front();
            }
        }
    }
    for(int i=0;i<=n-k;i++){
        printf("%d%c",b[i],i==n-k?'\n':' ');
    }
}

int main(){
    while(scanf("%d%d",&n,&k)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}
