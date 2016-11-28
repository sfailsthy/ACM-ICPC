//created by sfailsthy 2016/11/29 2:46
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn =20;
int dx[]={1,-1,0,0,0};
int dy[]={0,0,1,-1,0};

int M,N;
int tile[maxn][maxn];
int opt[maxn][maxn];
int flip[maxn][maxn];

int get(int x,int y){
    int c=tile[x][y];

    for(int i=0;i<5;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<M&&ny>=0&&ny<N){
            c+=flip[nx][ny];
        }
    }
    return c%2;
}

int calc(){
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(get(i-1,j)!=0){
                flip[i][j]=1;
            }
        }
    }

    for(int j=0;j<N;j++){
        if(get(M-1,j)!=0){
            return -1;
        }
    }

    int res=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            res+=flip[i][j];
        }
    }
    return res;
}

void solve(){
    int res=-1;

    for(int i=0;i<(1<<N);i++){
        memset(flip,0,sizeof(flip));
        for(int j=0;j<N;j++){
            flip[0][N-1-j]=i>>j&1;
        }

        int num=calc();
        if(num>=0&&(res<0||res>num)){
            res=num;
            memcpy(opt,flip,sizeof(flip));
        }
    }

    if(res<0){
        printf("IMPOSSIBLE\n");
    }
    else{
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                printf("%d",opt[i][j]);
                if(j==N-1) printf("\n");
                else printf(" ");
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        M=5;
        N=6;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&tile[i][j]);
            }
        }
        printf("PUZZLE #%d\n",++kase);
        solve();
    }


    return 0;
}
