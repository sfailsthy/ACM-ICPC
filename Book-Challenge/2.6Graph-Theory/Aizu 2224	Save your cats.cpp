//created by sfailsthy 2016/11/27 14:38
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn =10000+10;
int X[maxn];
int Y[maxn];
struct edge{
    int u,v;
    double cost;
};
edge es[maxn*maxn];

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

double kruscal(){
    sort(es,es+E,cmp);
    init(V);

    double res=0;
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin>>V>>E){
        for(int i=0;i<V;i++){
            cin>>X[i]>>Y[i];
        }
        double sum=0;
        for(int i=0;i<E;i++){
            int p,q;
            cin>>p>>q;
            p--;
            q--;
            int dx=X[p]-X[q];
            int dy=Y[p]-Y[q];
            double cost=sqrt(dx*dx+dy*dy);
            sum+=cost;
            es[i]=(edge){p,q,cost};
        }

        printf("%.3f\n", sum-kruscal());
    }
    return 0;
}
