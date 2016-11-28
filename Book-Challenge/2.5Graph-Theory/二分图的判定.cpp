//created by sfailsthy 2016/11/27 11:56
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=1000+10;

vector<int> G[maxn];
int V,E;
int color[maxn];//1或者-1

//把顶点染成1或者-1
bool dfs(int v,int c){
    color[v]=c;

    for(int i=0;i<G[v].size();i++){
        if(color[G[v][i]]==c){
            return false;
        }

        if(color[G[v][i]]==0&&!dfs(G[v][i],-c)){
            return false;
        }
    }

    return true;
}

void solve(){
    memset(color,0,sizeof(color));

    for(int i=0;i<V;i++){
        if(color[i]==0){
            if(!dfs(i,1)){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin>>V&&V){
        for(int i=0;i<V;i++){
            G[i].clear();
        }
        cin>>E;
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        solve();
    }
    return 0;

}
