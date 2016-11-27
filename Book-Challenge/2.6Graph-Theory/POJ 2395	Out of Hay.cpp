//created by sfailsthy 2016/11/27 19:54
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn =2000+10;
const int maxe=10000+10;
#define INF 0x3f3f3f3f

int V,E;
struct edge{
    int u,v,cost;
};
edge es[maxe];

bool cmp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

int par[maxn];
int rank[maxn];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
    }
}

int find(int x){
    if(par[x]==x){
        return x;
    }

    else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);

    if(x==y) return;

    if(rank[x]<rank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(rank[x]==rank[y]){
            rank[x]++;
        }
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

int kruscal(){
    sort(es,es+E,cmp);
    init(V);

    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res=max(res,e.cost);
        }
    }
    return res;
}

int main(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        u--;
        v--;
        es[i]=(edge){u,v,d};
    }

    printf("%d\n", kruscal());
    return 0;
}
