//created by sfailsthy 2016/12/22 16:37
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn =300+10;
const int Mod =10007;
typedef long long LL;

struct Point{
    int x,y;
    Point(){}
    
    Point(int x,int y):x(x),y(y){
    }
    
    Point operator + (Point p){
        return Point(x+p.x,y+p.y);
    }
    
    Point operator - (Point p){
        return Point(x-p.x,y-p.y);
    }
    
    int dot(Point p){
        //内积
        return x*p.x+y*p.y;
    }

    int det(Point p){
        //外积
        return x*p.y-y*p.x;
    }
};

//判断点p是否在线段p1-p2上
bool on_seg(Point p1,Point p2,Point p){
    return (p1-p).det(p2-p)==0&&(p1-p).dot(p2-p)<=0;
}

int dist2(Point p1,Point p2){
    int dx=p1.x-p2.x;
    int dy=p1.y-p2.y;
    return dx*dx+dy*dy;
}

int n,R;
Point P[maxn];
bool isconnected[maxn][maxn];
int degree[maxn];
LL C[maxn][maxn];

void init(){
    memset(isconnected,true,sizeof(isconnected));

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(k==i||k==j) continue;
                if(on_seg(P[i],P[j],P[k])){
                    isconnected[i][j]=isconnected[j][i]=false;
                    break;
                }
            }
        }
    }

    memset(degree,0,sizeof(degree));
    memset(C,0,sizeof(C));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isconnected[i][j]&&dist2(P[i],P[j])<=R*R){
                C[i][j]=C[j][i]=-1;
                degree[i]++;
                degree[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        C[i][i]=degree[i];
    }
}

LL det(LL a[][maxn],int n){
    LL ret=1;
    for(int i=0;i<n;i++){
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
            return -1;
        }

        ret=(ret*a[i][i])%Mod;
    }

    return (ret+Mod)%Mod;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&R);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            P[i]=Point(x,y);
        }

        init();
        printf("%lld\n",det(C,n-1));
    }
    return 0;
}
