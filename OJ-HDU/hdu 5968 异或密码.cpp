//created by sfailsthy 2016/11/23 23:22
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define INF 0x7fffffff
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        int a[110];
        int sub[110][110];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        for(int i=0;i<n;i++){
            int x=0;
            for(int j=i;j<n;j++){
                x^=a[j];
                sub[i][j]=x;
            }
        }

        scanf("%d",&m);
        while(m--){
            int x;
            scanf("%d",&x);
            int ans=INF;
            int len=0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    if(abs(sub[i][j]-x)<ans){
                        len=j-i+1;
                        ans=abs(sub[i][j]-x);
                    }

                    else if(abs(sub[i][j]-x)==ans){
                        len=max(len,j-i+1);
                    }
                }
            }
            printf("%d\n",len);
        }
        printf("\n");
    }
    return 0;
}
