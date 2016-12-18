//created by sfailsthy 2016/12/18 16:14
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn =100000+10;
int n,m;
int Left[maxn],Right[maxn];

inline void Link(int L,int R){
    Right[L]=R;
    Left[R]=L;
}

int main(){
    int kase=0;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            Left[i]=i-1;
            Right[i]=(i+1)%(n+1);
        }
        Right[0]=1;
        Left[0]=n;

        int op,X,Y,inv=0;

        for(int i=0;i<m;i++){
            scanf("%d",&op);
            if(op==4) inv=!inv;
            else{
                scanf("%d%d",&X,&Y);
                if(op==3&&Right[Y]==X) swap(X,Y);
                if(op!=3&&inv) op=3-op;
                if(op==1&&X==Left[Y]) continue;
                if(op==2&&X==Right[Y]) continue;

                int LX=Left[X],RX=Right[X],LY=Left[Y],RY=Right[Y];
                if(op==1){
                    Link(LX,RX);
                    Link(LY,X);
                    Link(X,Y);
                }

                else if(op==2){
                    Link(LX,RX);
                    Link(Y,X);
                    Link(X,RY);
                }

                else if(op==3){
                    if(Right[X]==Y){
                        Link(LX,Y);
                        Link(Y,X);
                        Link(X,RY);
                    }
                    else{
                        Link(LX,Y);
                        Link(Y,RX);
                        Link(LY,X);
                        Link(X,RY);
                    }
                }
            }
        }

        int b=0;
        long long res=0;
        for(int i=1;i<=n;i++){
            b=Right[b];
            if(i&1) res+=b;
        }

        if(inv&&(n&1)==0){
            res=(long long)n*(n+1)/2-res;
        }
        printf("Case %d: %lld\n",++kase,res);
    }
}
