//created by sfailsthy 2016/11/23 20:13
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn =3*50000+10;
const int maxk =1e5+10;
int N,K;
int D[maxk],X[maxk],Y[maxk];

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

void solve(){
    init(3*N);

    int ans=0;
    for(int i=0;i<K;i++){
        int t=D[i];
        int x=X[i]-1,y=Y[i]-1;

        if(x<0||x>=N||y<0||y>=N){
            ans++;
            continue;
        }

        if(t==1){
            if(same(x,y+N)||same(x,y+2*N)){
                ans++;
            }

            else{
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            }
        }

        else{
            if(same(x,y)||same(x,y+2*N)){
                ans++;
            }
            else{
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++){
        scanf("%d%d%d",&D[i],&X[i],&Y[i]);
    }
    solve();
    return 0;
}
