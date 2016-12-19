//created by sfailsthy 2016/12/20 239
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
const int maxn =30;

int n,m;
int G[maxn][maxn];
int vis[maxn];
string name[maxn];
map<string,int> Index;
vector<string> vec;

int ID(string s){
    if(Index.count(s)) return Index[s];
    vec.push_back(s);
    return Index[s]=vec.size()-1;
}

void floyd_warshall(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                G[i][j]|=G[i][k]&&G[k][j];
            }
        }
    }
}

void dfs(int u){
    vis[u]=1;
    for(int v=0;v<n;v++){
        if(!vis[v]&&G[u][v]&&G[v][u]){
            cout<<", "<<name[v];
            dfs(v);
        }
    }
}

void solve(){
    floyd_warshall();

    memset(vis,0,sizeof(vis));
    for(int u=0;u<n;u++){
        if(!vis[u]){
            cout<<name[u];
            dfs(u);
            printf("\n");
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kase=0;
    while(cin>>n>>m&&n){
        memset(G,0,sizeof(G));
        vec.clear();
        Index.clear();

        string str1,str2;
        for(int i=0;i<m;i++){
            cin>>str1>>str2;
            int a=ID(str1),b=ID(str2);
            name[a]=str1;
            name[b]=str2;
            G[a][b]=1;
        }
        if(kase>0) printf("\n");
        printf("Calling circles for data set %d:\n",++kase);
        solve();
    }
    return 0;
}
