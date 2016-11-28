//created by sfailsthy 2016/11/27 13:24
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn =1000+10;
const int maxe= 20000+10;

struct edge{
    int u,v,cost;
};
edge es[maxe];

bool cmp(const edge& e1,const edge& e2){
    return e1.cost>e2.cost;
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
int in_tree;

int kruscal(){
    sort(es,es+E,cmp);
    init(V);
    in_tree=1;
    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
            in_tree++;
        }
    }

    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        u--;
        v--;
        es[i]=(edge){u,v,cost};
    }
    int ans=kruscal();
    if(in_tree<V){
        ans=-1;
    }
    cout<<ans<<endl;
    return 0;
}
