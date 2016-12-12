//created by sfailsthy 2016/12/12 19:19
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn =1e5+10;
int n;
int h[maxn];
int L[maxn],R[maxn];

void solve(){
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty()&&h[s.top()]>=h[i]){
            s.pop();
        }
        L[i]=(s.empty())?0:(s.top()+1);
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&h[s.top()]>=h[i]){
            s.pop();
        }
        R[i]=(s.empty())?n:s.top();
        s.push(i);
    }

    long long res=0;
    for(int i=0;i<n;i++){
        res=max(res,(long long)h[i]*(R[i]-L[i]));
    }
    printf("%lld\n",res);
}

int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&h[i]);
        }
        solve();
    }
    return 0;
}
