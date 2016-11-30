//created by sfailsthy 2016/10/31 1:36
#include <iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;

const int maxn=10000+10;
int a[maxn];

int main()
{
    int kase=0;
    int n,q;
    while(cin>>n>>q&&n&&q){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<"CASE# "<<++kase<<":"<<endl;
        while(q--){
            int x;
            cin>>x;
            int p=lower_bound(a,a+n,x)-a;
            if(a[p]==x) cout<<x<<" found at "<<p+1<<endl;
            else cout<<x<<" not found"<<endl;
        }
    }
    return 0;
}
