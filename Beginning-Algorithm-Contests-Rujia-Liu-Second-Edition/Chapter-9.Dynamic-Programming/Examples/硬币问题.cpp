//created by sfailsthy 2016/11/28 23:54
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn =1000+10;
int n,S;
int V[maxn];
int minv[maxn];
int maxv[maxn];

void print_ans(int* d,int S){
    for(int i=0;i<n;i++){
        if(S>=V[i]&&d[S]==d[S-V[i]]+1){
            printf("%d",i+1);
            print_ans(d,S-V[i]);
            break;
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&V[i]);
        }
        minv[0]=maxv[0]=0;
        for(int i=1;i<=S;i++){
            minv[i]=INF;
            maxv[i]=-INF;
        }

        for(int i=1;i<=S;i++){
            for(int j=0;j<n;j++){
                if(i>=V[j]){
                    minv[i]=min(minv[i],minv[i-V[j]]+1);
                    maxv[i]=max(maxv[i],maxv[i-V[j]]+1);
                }
            }
        }

        printf("%d %d\n",minv[S],maxv[S]);
        print_ans(minv,S);
        printf("\n");
        print_ans(maxv,S);
        printf("\n");
    }
    return 0;
}
