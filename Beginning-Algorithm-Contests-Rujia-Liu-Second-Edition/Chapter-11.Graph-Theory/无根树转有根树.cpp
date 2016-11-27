//created by sfailsthy 2016/11/28 1:20
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn =1e6+10;

int n;
vector<int> G[maxn];
int p[maxn];

void read_tree(){
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u,int fa){
    int d=G[u].size();

    for(int i=0;i<d;i++){
        int v=G[u][i];
        if(v!=fa) dfs(v,p[v]=u);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        read_tree();
        p[1]=-1;
        dfs(1,-1);
        for(int i=0;i<n;i++){
            cout<<"("<<i<<","<<p[i]<<")"<<endl;
        }
    }
    return 0;
}
