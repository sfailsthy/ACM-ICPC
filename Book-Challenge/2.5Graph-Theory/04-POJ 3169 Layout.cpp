//created by sfailsthy 2016/11/27 23:15
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn=1000+10;
const int maxe=10000+10;
int AL[maxe],BL[maxe],DL[maxe];
int AD[maxe],BD[maxe],DD[maxe];
int N,ML,MD;
int d[maxn];

void solve(){
    fill(d,d+N,INF);
    d[0]=0;

    //利用Bellman-Ford算法计算
    for(int k=0;k<N;k++){
        for(int i=0;i+1<N;i++){
            if(d[i+1]<INF){
                d[i]=min(d[i],d[i+1]);
            }
        }

        for(int i=0;i<ML;i++){
            if(d[AL[i]-1]<INF){
                d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
            }
        }

        for(int i=0;i<MD;i++){
            if(d[BD[i]-1]<INF){
                d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
            }
        }
    }

    int res=d[N-1];
    if(d[0]<0){
        res=-1;
    }
    else if(res==INF){
        res=-2;
    }
    printf("%d\n",res);
}

int main(){
    scanf("%d%d%d",&N,&ML,&MD);
    for(int i=0;i<ML;i++){
        scanf("%d%d%d",&AL[i],&BL[i],&DL[i]);
    }

    for(int i=0;i<MD;i++){
        scanf("%d%d%d",&AD[i],&BD[i],&DD[i]);
    }

    solve();
    return 0;
}
