//created by sfailsthy 2016/12/12 19:55
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
const int maxn =100+10;
int n,W;
int w[maxn],v[maxn],m[maxn];
int dp[100*maxn];

void solve(){
    for(int i=0;i<n;i++){
        for(int a=0;a<w[i];a++){
            deque<int> deq,deqv;
            for(int j=0;j*w[i]+a<=W;j++){
                int val=dp[j*w[i]+a]-j*v[i];
                while(!deq.empty()&&deqv.back()<=val){
                    deq.pop_back();
                    deqv.pop_back();
                }
                deq.push_back(j);
                deqv.push_back(val);
                dp[j*w[i]+a]=deqv.front()+j*v[i];
                if(deq.front()==j-m[i]){
                    deq.pop_front();
                    deqv.pop_front();
                }
            }
        }
    }
    printf("%d\n",dp[W]);
}

int main(){
   scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&w[i],&v[i],&m[i]);
    }
    solve();
    return 0;
}
