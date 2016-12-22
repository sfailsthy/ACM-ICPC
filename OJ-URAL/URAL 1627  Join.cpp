//created by sfailsthy 2016/12/22 12:46
//不是很懂取模，WA了好多次。。
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn =81+10;
typedef long long LL;

char field[10][10];
int degree[maxn];
bool G[maxn][maxn];
LL C[maxn][maxn];
int num[10][10];
int n,m;
int cnt;

const int Mod=1000000000;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

LL det(LL a[][maxn],int n){
    LL ret=1;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            while(a[j][i]){
                LL t=a[i][i]/a[j][i];
                for(int k=i;k<n;k++){
                    a[i][k]=(a[i][k]-a[j][k]*t)%Mod;
                }

                for(int k=i;k<n;k++){
                    swap(a[i][k],a[j][k]);
                }

                ret=-ret;
            }
        }

        if(a[i][i]==0){
            return 0;
        }
        ret=(ret*a[i][i])%Mod;
    }
    
    return (ret+Mod)%Mod;
}

void solve(){
   memset(degree,0,sizeof(degree));
   memset(C,0,sizeof(C));

   for(int i=0;i<cnt;i++){
        for(int j=i+1;j<cnt;j++){
            if(G[i][j]){
                C[i][j]=C[j][i]=-1;
                degree[i]++;
                degree[j]++;
            }
            
        }
   } 

   for(int i=0;i<cnt;i++){
        C[i][i]=degree[i];
   }
   printf("%lld\n",det(C,cnt));
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        cnt=0;
        for(int i=0;i<n;i++){
            scanf("%s",field[i]);
            for(int j=0;j<m;j++){
                if(field[i][j]=='.'){
                    num[i][j]=cnt++;
                }
            }
        }

        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(field[i][j]=='*') continue;
                int u=num[i][j];
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0||x>=n||y<0||y>=m) continue;
                    if(field[x][y]=='*') continue;
                    int v=num[x][y];
                    G[u][v]=G[v][u]=1;
                }
            }
        }
        solve();
    }
    return 0;
}
