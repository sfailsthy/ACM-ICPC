//created by sfailsthy 2016/12/20 23:50
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn =100+10;

int n,m,q;
int d[maxn][maxn];

void floyd_warshall(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
}

int  main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int kase=0;
    while(scanf("%d%d%d",&n,&m,&q)==3&&n){
        if(kase) printf("\n");
        printf("Case #%d\n",++kase);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=INF;
            }
            d[i][i]=0;
        }

        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            d[a][b]=min(d[a][b],c);
            d[b][a]=d[a][b];
        }

        floyd_warshall();

        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            if(d[a][b]==INF){
                printf("no path\n");
            }
            else{
                printf("%d\n",d[a][b]);
            }
        }
    }
    return 0;
}
