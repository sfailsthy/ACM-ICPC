//created by sfailsthy 2017/1/18 21:03
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn =50+10;

struct edge{
    int from,to;
    double cost;
};

vector<edge> es;
double d[maxn];
int n,m;

bool find_negative_loop(){
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++){
        for(int j=0;j<es.size();j++){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;

                if(i==n-1){
                    return true;
                }
            }
        }
    }
    return false;
}

bool check(double mid){
    for(int i=0;i<es.size();i++){
        es[i].cost-=mid;
    }
    bool flag=find_negative_loop();
    for(int i=0;i<es.size();i++){
        es[i].cost+=mid;
    }
    return flag;
}

int main(){
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        es.clear();
        int ub=0;
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            ub=max(ub,w);
            es.push_back(edge{u,v,w});
        }

        printf("Case #%d: ",++kase);
        if(!check(ub+1)){
            printf("No cycle found.\n");
        }
        else{
            double L=0,R=ub;
            while(R-L>1e-3){
                double M=L+(R-L)/2;
                if(check(M)){
                    R=M;
                }
                else{
                    L=M;
                }
            }
            printf("%.2lf\n",R);
        }
    }
    return 0;
}
