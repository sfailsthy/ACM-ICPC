//created by sfailsthy 2016/11/23 20:19
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn =1000+10;

int par[maxn];
int rank[maxn];

//初始化n个元素
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
    }
}

//查询树的根
int find(int x){
    if(par[x]==x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

//合并x和y所属的集合
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

//判断x和y是否属于同一集合
bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
    int N,d;
    int x[maxn],y[maxn];
    int dist[maxn][maxn];
    bool mark[maxn];

    scanf("%d%d",&N,&d);
    for(int i=0;i<N;i++){
        scanf("%d%d",&x[i],&y[i]);
    }

    memset(dist,0,sizeof(dist));
    memset(mark,0,sizeof(mark));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            int dx=x[i]-x[j];
            int dy=y[i]-y[j];
            dist[i][j]=dx*dx+dy*dy;
        }
    }

    init(N);
    char c;
    while(cin>>c){
        if(c=='O'){
            int p;
            scanf("%d",&p);
            p--;
            mark[p]=true;

            for(int q=0;q<N;q++){
                if(q==p) continue;
                if(mark[q]&&dist[p][q]<=d*d){
                    unite(p,q);
                }
            }
        }

        else{
            int p,q;
            scanf("%d%d",&p,&q);
            p--;
            q--;
            if(same(p,q)){
                printf("SUCCESS\n");
            }
            else{
                printf("FAIL\n");
            }
        }
    }
    return 0;
}
