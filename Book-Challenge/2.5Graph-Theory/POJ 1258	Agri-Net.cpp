//created by sfailsthy 2016/11/27 13:21
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn =100+10;

struct edge{
    int u,v,cost;
};
edge es[maxn*maxn];

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
    while(cin>>V){
        E=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                int x;
                cin>>x;
                if(i==j) continue;
                es[E++]=(edge){i,j,x};
            }
        }
        cout<<kruscal()<<endl;
    }
    return 0;
}
