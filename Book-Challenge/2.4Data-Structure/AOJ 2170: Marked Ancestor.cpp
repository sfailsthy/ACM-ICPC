//created by sfailsthy 2016/11/24 19:29
//这个貌似没用到并查集，合并查找的基本操作都没用到。。。
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn =1e5+10;
int par[maxn];
bool mark[maxn];

int find(int x){
    if(mark[x]){
        return x;
    }

    else{
        return find(par[x]);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q;
    while(scanf("%d%d",&n,&q)==2){
        if(n==0&&q==0) break;

        for(int i=2;i<=n;i++){
            int p;
            scanf("%d",&p);
            par[i]=p;
        }

        memset(mark,0,sizeof(mark));
        mark[1]=1;

        LL res=0;
        while(q--){
            char c;
            int p;
            cin>>c>>p;
            if(c=='M'){
                mark[p]=1;
            }

            else{
                res+=find(p);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
