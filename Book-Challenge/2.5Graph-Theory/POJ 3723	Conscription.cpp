//created by sfailsthy 2016/11/27 17:50
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn =20000+10;
const int maxe =50000+10;
struct edge{
    int u,v,cost;
};
edge es[maxe];

bool cmp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

int V,E;

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
            res+=e.cost;
        }
    }

    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,N,M,R;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&N,&M,&R);
        V=N+M;
        E=R;

        for(int i=0;i<R;i++){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            es[i]=(edge){x,N+y,-d};
        }
        printf("%d\n",10000*(N+M)+kruscal());
    }
    return 0;
}
