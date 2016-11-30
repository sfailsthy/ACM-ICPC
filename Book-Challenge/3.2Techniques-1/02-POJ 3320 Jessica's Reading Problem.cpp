//created by sfailsthy 2016/11/29 1:50
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int maxn =1000000+10;
int P;
int a[maxn];

void solve(){
    set<int> all;
    for(int i=0;i<P;i++){
        all.insert(a[i]);
    }
    int n=all.size();

    map<int,int> cnt;

    int s=0,t=0,res=P,num=0;
    for(;;){
        while(t<P&&num<n){
            if(cnt[a[t++]]++==0){
                num++;
            }

        }
        if(num<n) break;
        res=min(res,t-s);
        if(--cnt[a[s++]]==0){
            num--;
        }
    }

    printf("%d\n",res);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&P)!=EOF){
        for(int i=0;i<P;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}
