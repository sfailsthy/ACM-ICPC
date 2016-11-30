//created by sfailsthy 2016/11/29 14:20
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =20+10;
int n;
int bowl[maxn];
int flip[maxn];

int get(int x){
    int c=bowl[x];

    for(int i=x-1;i<=x+1;i++){
        if(i>=0&&i<n) c+=flip[i];
    }
    return c%2;
}

int calc(){
    for(int i=1;i<n;i++){
        if(get(i-1)!=0){
            flip[i]=1;
        }
    }

    int res=0;
    for(int i=0;i<n;i++){
        res+=flip[i];
    }
    return res;
}

int main(){
    n=20;
    for(int i=0;i<n;i++){
        scanf("%d",&bowl[i]);
    }

    int res=20+1;
    memset(flip,0,sizeof(flip));
    int res1=calc();
    memset(flip,0,sizeof(flip));
    flip[0]=1;
    int res2=calc();
    res=min(res1,res2);
    printf("%d\n",res);
    return 0;
}
