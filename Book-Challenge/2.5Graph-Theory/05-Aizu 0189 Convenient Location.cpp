//created by sfailsthy 2016/11/27 17:31
/*
0x7fffffff会溢出，但是0x3f3f3f3f不会，以后还是用0x3f3f3f3f吧。。。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int maxn =15;
#define INF 0x3f3f3f3f

int V;
int d[maxn][maxn];

void warshall_floyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    while(cin>>n&&n){
        V=0;
        for(int i=0;i<maxn;i++){
            for(int j=0;j<maxn;j++){
                d[i][j]=INF;
            }
            d[i][i]=0;
        }

        V=0;
        for(int i=0;i<n;i++){
            int u,v,x;
            cin>>u>>v>>x;
            d[u][v]=d[v][u]=x;
            V=max(V,max(u,v)+1);
        }

        warshall_floyd();
        int ans=INF,res=0;
        for(int i=0;i<V;i++){
            int tmp=0;
            for(int j=0;j<V;j++){
                tmp+=d[i][j];
            }

            if(tmp<ans){
                ans=tmp;
                res=i;
            }
        }

        cout<<res<<" "<<ans<<endl;
    }
    return 0;
}
