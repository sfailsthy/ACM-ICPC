//created by sfailsthy 2016/11/23 20:20
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn =2e5+10;

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
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M;
        scanf("%d%d",&N,&M);
        init(2*N);
        for(int i=0;i<M;i++){
            char c;
            int p,q;
            cin>>c;
            scanf("%d%d",&p,&q);
            if(c=='A'){
                if(same(p,q+N)){
                    printf("In different gangs.\n");
                }
                else if(same(p,q)){
                    printf("In the same gang.\n");
                }
                else{
                    printf("Not sure yet.\n");
                }
            }

            else{
                unite(p,q+N);
                unite(q,p+N);
            }
        }

    }
    return 0;
}
