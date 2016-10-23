#include<iostream>  
#include<cstdio>  
using namespace std;  
#define maxk 100005  
#define maxn 50000+5  
int par[3*maxn];//父亲  
int Rank[3*maxn];//树的高度  
//初始化  
void init(int n)  
{  
    for(int i=0;i<n;i++){  
        par[i]=-1;  
        Rank[i]=0;  
    }  
}  
//查询父亲，路径压缩  
int Find(int x)  
{  
    int s;  
    for(s=x;par[s]!=-1;s=par[s]);  
    while(s!=x){  
        int temp=par[x];  
        par[x]=s;  
        x=temp;  
    }  
    return s;  
}  
//合并x，y属于的集合  
void unite(int x,int y)  
{  
    x=Find(x);y=Find(y);  
    if(x==y) return;  
    if(Rank[x]<Rank[y]){  
        par[x]=y;  
    }  
    else{  
        par[y]=x;  
        if(Rank[x]==Rank[y]) Rank[x]++;  
    }  
}  
bool same(int x,int y)  
{  
    return Find(x)==Find(y);  
}  
int n,k;  
int T[maxk],X[maxk],Y[maxk];  
int main()  
{  
    scanf("%d%d",&n,&k);  
    for(int i=0;i<k;i++){  
        scanf("%d%d%d",&T[i],&X[i],&Y[i]);  
        X[i]--;Y[i]--;  
    }  
    //初始化并查集，元素x,x+n,x+2*n分别表示x-A,x-B,x-C  
    init(3*n);  
    int ans=0;  
    for(int i=0;i<k;i++){  
        int t=T[i];  
        int x=X[i],y=Y[i];  
        if(x<0||x>=n||y<0||y>=n){  
            ans++;  
            continue;  
        }  
        if(t==1){  
            //x和y属于同一类  
            if(same(x,y+n)||same(x,y+2*n)){  
                ans++;  
            }  
            else{  
                unite(x,y);  
                unite(x+n,y+n);  
                unite(x+2*n,y+2*n);  
            }  
        }  
        else{  
            //x吃y  
            if(same(x,y)||same(x,y+2*n)){  
                ans++;  
            }  
            else{  
                unite(x,y+n);  
                unite(x+n,y+2*n);  
                unite(x+2*n,y);  
            }  
        }  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
