//created by sfailsthy 2016/11/23 20:47
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int maxn =10000+10;

int L,P,N;
int A[maxn],B[maxn],X[maxn];
pair<int,int> pir[maxn];

void solve(){
    A[N]=L;
    B[N]=0;
    N++;

    priority_queue<int> que;

    int ans=0,pos=0,tank=P;

    for(int i=0;i<N;i++){
        int d=A[i]-pos;

        while(tank-d<0){
            if(que.empty()){
                cout<<"-1"<<endl;
                return;
            }

            tank+=que.top();
            que.pop();
            ans++;
        }

        tank-=d;
        pos=A[i];
        que.push(B[i]);
    }
    cout<<ans<<endl;
    return;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>X[i]>>B[i];
    }
    cin>>L>>P;
    for(int i=0;i<N;i++){
        A[i]=L-X[i];
    }
    for(int i=0;i<N;i++){
        pir[i]=make_pair(A[i],B[i]);
    }
    sort(pir,pir+N);
    for(int i=0;i<N;i++){
        A[i]=pir[i].first;
        B[i]=pir[i].second;
    }
    solve();
    return 0;
}
