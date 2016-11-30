#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

const int maxn =1e7+10;
vector<ll> a,b;
ll n;

void solve(){
    ll s=1,t=1,sum=0,res=0;
    for(;;){
        while(t*t<=n&&sum<n){
            sum+=t*t;
            t++;
        }
        if(sum<n) break;
        else if(sum==n){
            a.push_back(s);
            b.push_back(t-1);
            res++;
        }
        sum-=s*s;
        s++;
    }

    printf("%lld\n",res);
    for(int i=0;i<res;i++){
        cout<<b[i]-a[i]+1<<" ";
        for(int j=a[i];j<b[i];j++){
            cout<<j<<" ";
        }
        cout<<b[i]<<endl;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%lld",&n);
    solve();
    return 0;
}
