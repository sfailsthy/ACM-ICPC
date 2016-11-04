//created by sfailsthy 2016/11/5 0:52
//注意n=1时特别处理一下就行
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;

const int maxn =50+10;
deque<int> deq;
int a[maxn];

void solve()
{
    int p=0;
    while(deq.size()>=2){
        a[p]=deq.front();
        deq.pop_front();
        int x=deq.front();
        deq.pop_front();
        deq.push_back(x);
        p++;
    }
    cout<<"Discarded cards:";
    for(int i=0;i<p-1;i++){
        cout<<" "<<a[i]<<",";
    }
    cout<<" "<<a[p-1]<<endl;
    cout<<"Remaining card: "<<deq.front()<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n&&n){
        if(n==1){
            cout<<"Discarded cards:"<<endl<<"Remaining card: 1"<<endl;
        }
        else{
            while(!deq.empty()) deq.pop_back();
            for(int i=1;i<=n;i++){
                deq.push_back(i);
            }
            solve();
        }
    }
    return 0;
}
