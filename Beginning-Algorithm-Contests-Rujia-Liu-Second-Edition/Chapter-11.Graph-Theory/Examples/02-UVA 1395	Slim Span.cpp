//created by sfailsthy 2016/12/20 1:42
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =100+10;
struct edge{
    int u,v,cost;
    bool operator < (const edge& rhs) const{
        return cost<rhs.cost;
    }
};
edge es[maxn*maxn/2];

int  V,E;
int par[maxn];
int ran[maxn];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        ran[i]=0;
    }
}

int find(int x){
    if(par[x]==x) return x;
    else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);

    if(x==y) return;
    if(ran[x]<ran[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(ran[x]==ran[y]){
            ran[x]++;
        }
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

void solve(){
    sort(es,es+E);
    int res=INF;
    for(int L=0;L<E;L++){
        init(V);
        int cnt=V;
        for(int R=L;R<E;R++){
            int u=es[R].u,v=es[R].v;
            if(!same(u,v)){
                unite(u,v);
                if(--cnt==1){
                    res=min(res,es[R].cost-es[L].cost);
                    break;
                }
            }
        }
    }

    if(res==INF) res=-1;
    printf("%d\n",res);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&V,&E)==2&&V){
        for(int i=0;i<E;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            es[i]=(edge){a-1,b-1,c};
        }
        solve();
    }
}
