//created by sfailsthy 2016/11/28 11:45
/*
想到了Bellman-Ford算法判断是否存在负圈，然而对题目的输入方式理解错误，样例都过不了。。。搜了别人的题解，改一下输入，直接Accepted。。。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> P;

const int MAX_V =500+10;
const int MAX_E =5500+10;
struct edge{
    int from,to,cost;
};

edge es[MAX_E];
int d[MAX_V];
int F,N,M,W,E;

bool find_negative_loop(){
    memset(d,0,sizeof(d));

    for(int i=0;i<N;i++){
        for(int j=0;j<E;j++){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;

                if(i==N-1) return true;
            }
        }
    }
    return false;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&F);
    for(int k=0;k<F;k++){
        scanf("%d%d%d",&N,&M,&W);
        E=0;
        for(int i=0;i<M;i++){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            s--;
            e--;
            es[E++]=(edge){s,e,t};
            es[E++]=(edge){e,s,t};
        }

        for(int i=0;i<W;i++){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            s--;
            e--;
            es[E++]=(edge){s,e,-t};
        }

        bool flag=find_negative_loop();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
